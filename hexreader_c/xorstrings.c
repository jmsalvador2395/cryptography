#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bytestrings.h"
int main(int argc, char** argv){
	int inputsize, convertedsize;
	inputsize=strlen(argv[1]);
	convertedsize=inputsize/2;

	unsigned char str1[convertedsize];
	unsigned char str2[convertedsize];
	unsigned char str3[convertedsize];
	tohex(argv[1], inputsize, str1, convertedsize);
	tohex(argv[2], inputsize, str2, convertedsize);

	xor_to_output(str1, str2, str3, convertedsize);
	for(int i=0; i<convertedsize; i++){
		printf("index: %d\n", i);
		printf("%02x\t%02x\t%02x\n", str1[i], str2[i], str3[i]);
		printf("%c\t%c\t%c\n", str1[i], str2[i], str3[i]);
		printf("\n\n");
	}
	printf("\n");
/*
	printf("ascii output\n");
	for(int i=0; i<convertedsize; i++){
		printf("%c\t%c\t%c\n", str1[i], str2[i], str3[i]);
	}
*/


	return 0;
}
