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

void bytencpy(CryptoPP::byte* input, CryptoPP::byte* output, int n){
	for(int i=0; i<n;i++)
		output[i]=input[i];
}

void byte_xor_block(CryptoPP::byte* input, CryptoPP::byte* target){
	for(int i=0; i<16; i++)
		target[i]=target[i]^input[i];
}

int main(int argc, char** argv){
	if(argc != 3){
		printf("usage:\n\t./aescbc256 [256-bit aes key] [cipher text]\n");
		return 1;
	}
	
	int keylen=strlen(argv[1])/2;
	int cipherlen=strlen(argv[2])/2-16;

	if(cipherlen%16>0){
		printf("Error: Cipher length is not a multiple of 16\n");
		return 1;
	}

	//decode the string of hex into its actual bits
	tohex_in_place((unsigned char*)argv[1], keylen*2);
	tohex_in_place((unsigned char*)argv[2], strlen(argv[2]));

	//delcare key and iv
	CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[16], temp[16];

	for(int i=0; i<16; i++){
		key[i]=argv[1][i];
		iv[i]=argv[2][i];
	}
	
	//initialize decryptor
	CryptoPP::AES::Decryption aes;
	aes.SetKey(key, keylen);

	//create string to hold ciphertext
	CryptoPP::byte cipher[cipherlen];
	for(int i=0; i<cipherlen; i++)
		cipher[i]=argv[2][i+16];

	//cbc mode processing
	for(int i=0; i<cipherlen; i=i+16){
		bytencpy(&cipher[i], temp, 16);

		aes.ProcessBlock(&cipher[i]);
		byte_xor_block(iv, &cipher[i]);

		bytencpy(temp, iv, 16);
	}
	
	//remove pad
	int padlen=cipher[cipherlen-1];
	for(int i=0; i<padlen; i++)
		cipher[cipherlen-1-i]=0x0;

	printf("%s\n", (unsigned char*) cipher);

	return 0;
}
