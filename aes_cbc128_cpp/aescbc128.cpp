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

#include "../hexreader_c/bytestringspp.h"

int main(int argc, char** argv){
	if(argc != 3){
		printf("usage:\n\t./aescbc256 [256-bit aes key] [cipher text]\n");
		return 1;
	}
	
	int keylen=strlen(argv[1])/2;
	int cipherlen=strlen(argv[2])/2-16;

	tohex_in_place((unsigned char*)argv[1], keylen*2);
	tohex_in_place((unsigned char*)argv[2], strlen(argv[2]));

	CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[16];

	std::string encoded;
	CryptoPP::StringSource(key, sizeof(key), true,
		new CryptoPP::HexDecoder(
			new CryptoPP::StringSink(encoded)
		)
	);
	
	std::cout << "key: " << encoded << "\n";


	for(int i=0; i<16; i++){
		key[i]=argv[1][i];
		iv[i]=argv[2][i];
	}
	
	//CryptoPP::read_key(argv[1]
	//CryptoPP::SecByteBlock key(keylen);
	//TODO
	CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption d;
	d.SetKeyWithIV(key, sizeof(key), iv);
	//CryptoPP::AES::Decryption decryption(key, keylen, iv);
	//read in data
	//std::string key(argv[1]);
	std::string cipher(cipherlen, 0x0);
	std::cout << cipherlen <<"\n";
	for(int i=0; i<cipherlen; i++)
		cipher[i]=argv[2][i+16];
	std::string recovered;
	CryptoPP::StringSource s(cipher, true, 
							 new CryptoPP::StreamTransformationFilter(
							 d, new CryptoPP::StringSink(recovered)
							 )
	);

	//std::cout << "key:\t" << key << "\n";
	/*
	std::cout << "key:\t" << std::hex <<argv[1] << "\n";
	std::cout << "iv:\t" <<std::hex << iv << "\n";
	*/
	/*
	printf("key: ");
	for(int i=0; i<keylen; i++)
		printf("%02x ",(unsigned char) argv[1][i]);

	printf("\n");
	printf("iv: ");
	for(int i=0; i<16; i++)
		printf("%02x ", (unsigned char)argv[2][i]);
	printf("\n");
	*/

	std::cout << recovered <<"\n";
	return 0;
}
