#include <stdlib.h>
#include <stdio.h>
#include "cryptopp/cryptlib.h"
#include "cryptopp/integer.h"
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include "cryptopp/ccm.h"
#include "cryptopp/hex.h"
#include "cryptopp/modes.h"

#include "bytestringspp.h"
void tohex(unsigned char* input, int input_size,
		   unsigned char* output, int output_size){
	const char* pos=(const char*) input;
	int posint=0;
	for(int i=0; i<output_size; i++){ 
		sscanf(pos+posint, "%2hhx", &output[i]);
		posint +=2*sizeof(char);
	}

}

void tohex_in_place(unsigned char* inoutput, int input_size){
	const char* pos=(const char*) inoutput;
	int posint=0;
	for(int i=0; i<input_size/2; i++){ 
		sscanf(pos+posint, "%2hhx", &inoutput[i]);
		posint +=2*sizeof(char);
	}
	for(int i=input_size/2; i<input_size; i++)
		inoutput[i]=0x0;
	return;
}

void bytencpy(CryptoPP::byte* input, CryptoPP::byte* output, int n){
	for(int i=0; i<n;i++)
		output[i]=input[i];
}

void byte_xor_block(CryptoPP::byte* input, CryptoPP::byte* target){
	for(int i=0; i<16; i++)
		target[i]=target[i]^input[i];
}


void byte_xor(CryptoPP::byte* input, CryptoPP::byte* target, int length){
	for(int i=0; i<length; i++)
		target[i]=target[i]^input[i];
}
