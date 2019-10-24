#include "cryptopp/cryptlib.h"
#include "cryptopp/integer.h"
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include "cryptopp/ccm.h"
#include "cryptopp/hex.h"
#include "cryptopp/modes.h"



#ifndef _BYTE_STRINGS_PP_H_
#define _BYTE_STRINGS_PP_H

void tohex(unsigned char* input, int input_size, unsigned char* output, int output_size);

void tohex_in_place(unsigned char* input, int input_size);

void bytencpy(CryptoPP::byte* input, CryptoPP::byte* output, int n);

void byte_xor_block(CryptoPP::byte* input, CryptoPP::byte* target);

void byte_xor(CryptoPP::byte* input, CryptoPP::byte* target, int length);
	
#endif
