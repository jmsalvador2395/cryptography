#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>

#include "cryptopp/integer.h"
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"


int main(int argc, char** argv){
	if(argc != 3){
		printf("usage:\n\t./aescbc256 [256-bit aes key] [cipher text]\n");
		return 1;
	}
	
	int keylen=strlen(argv[1])/2;
	char* keybytes[strlen(argv[1])/2];


	CryptoPP::SecByteBlock key(keylen);

	//read in data
	//std::string key(argv[1]);
	std::string cipher(argv[2]);
	std::string iv(cipher.substr(0,15));
	cipher=cipher.substr(16, cipher.size());

	//std::cout << "key:\t" << key << "\n";
	std::cout << "cipher:\t" << cipher << "\n";
	std::cout << "iv:\t" << iv << "\n";
	return 0;
}
