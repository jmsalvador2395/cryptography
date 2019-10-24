#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>

#include "cryptopp/cryptlib.h"
#include "cryptopp/integer.h"
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include "cryptopp/ccm.h"
#include "cryptopp/hex.h"
#include "cryptopp/modes.h"

#include "../hexreader_c/bytestringspp.h"

//used for incrementing the last 64 bits of the IV
void add(CryptoPP::byte* iv, unsigned long long int adder){

	//put the last half of the IV into a long long int
	unsigned long long int sum=0;
	for(int i=8; i>0; i--){
		sum<<=8;
		sum=sum|iv[16-i];
	}

	//sum up the given adder and the IV
	sum+=adder;

	//put the result back into the last 64 bits of the IV
	for(int i=0; i<8; i++){
		iv[15-i]=sum&0xffff;
		sum>>=8;
	}
	return;
}

//putting cbc decryption into its own function so i can make it run in 
//parallel if i ever get off my lazy butt to do it
void ctr_decrypt(CryptoPP::AES::Encryption &aes,
				 CryptoPP::byte* ciphertext, int cipherlen,
				 CryptoPP::byte* iv, int start, int end){
	
	CryptoPP::byte f_out[16], temp_iv[16];
	memset(f_out, 0x0, 16);
	memset(temp_iv, 0x0, 16);
	bytencpy(iv, temp_iv, 16);

	add(temp_iv, start);
	
	//process chunks of 16 bytes
	for(int i=start; i<end/16; i++){
		aes.ProcessBlock(temp_iv, f_out);
		byte_xor(f_out, &ciphertext[i*16], 16);
		add(temp_iv, 1);
	}
	if(end%16!=0){
		aes.ProcessBlock(temp_iv, f_out);
		byte_xor(f_out, &ciphertext[end-end%16], end%16);
	}

	return;
}

int main(int argc, char** argv){
	if(argc != 3){
		printf("usage:\n\t./aesdecrypt [128-bit aes key] [cipher text]\n");
		return 1;
	}
	
	int keylen=strlen(argv[1])/2;
	int cipherlen=strlen(argv[2])/2-16;

	//decode the string of hex into its actual bits
	tohex_in_place((unsigned char*)argv[1], keylen*2);
	tohex_in_place((unsigned char*)argv[2], strlen(argv[2]));

	//delcare key and iv
	CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], 
				   iv[16],
				   temp[16];

	for(int i=0; i<16; i++){
		key[i]=argv[1][i];
		iv[i]=argv[2][i];
	}
	
	//initialize decryptor
	CryptoPP::AES::Encryption aes;
	aes.SetKey(key, keylen);

	//create byte array to hold ciphertext
	CryptoPP::byte cipher[cipherlen+1];

	//set last index to null character so printf doesn't print junk
	cipher[cipherlen]=0x0;
	for(int i=0; i<cipherlen; i++)
		cipher[i]=argv[2][i+16];

	//ctr mode processing
	ctr_decrypt(aes, cipher, cipherlen, iv, 0, cipherlen);
		
	printf("\nplaintext:\t%s\n\n", cipher);

	return 0;
}
