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
#include "cryptopp/osrng.h"

#include "../hexreader_c/bytestringspp.h"

int main(int argc, char** argv){
	if(argc != 2){
		printf("usage:\t./aesencrypt [plain text]\n");
		return 1;
	}

	CryptoPP::AutoSeededRandomPool prng;
	CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH];
	CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE];
	
	prng.GenerateBlock(key, sizeof(key));
	prng.GenerateBlock(iv, sizeof(iv));

	//create padded string
	int msglen=strlen(argv[1]);
	int padlen=16-msglen%16;
	CryptoPP::byte padded_text[msglen+padlen];
	bytencpy((CryptoPP::byte*) argv[1], padded_text, msglen);
	for(int i=msglen;i<msglen+padlen; i++)
		padded_text[i]=padlen;

	//initialize block cipher
	CryptoPP::AES::Encryption aes;
	aes.SetKey(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
	
	//run cbc mode on first block
	byte_xor_block(iv, padded_text);
	aes.ProcessBlock(padded_text);

	//cbc mode processing
	for(int i=16; i<msglen+padlen; i+=16){
		byte_xor_block(&padded_text[i-16], &padded_text[i]);
		aes.ProcessBlock(&padded_text[i]);
	}
	
	printf("\nAES Key:\t");
	for(int i=0; i<CryptoPP::AES::DEFAULT_KEYLENGTH; i++)
		printf("%02x", key[i]);
	
	//print ciphertext with prepended iv
	printf("\nCiphertext\t");
	for(int i=0; i<CryptoPP::AES::BLOCKSIZE; i++)
		printf("%02x", iv[i]);
	for(int i=0; i<msglen+padlen; i++)
		printf("%02x", padded_text[i]);
	printf("\n\n");
	
	return 0;
}
