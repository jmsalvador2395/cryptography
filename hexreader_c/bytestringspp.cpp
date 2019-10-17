#include <stdlib.h>
#include <stdio.h>
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

void tohex_in_place(unsigned char* input, int input_size){
	const char* pos=(const char*) input;
	int posint=0;
	for(int i=0; i<input_size/2; i++){ 
		sscanf(pos+posint, "%2hhx", &input[i]);
		posint +=2*sizeof(char);
	}
}
