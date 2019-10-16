#include <stdio.h>
#include <stdlib.h>
#include "bytestrings.h"

void tohex(unsigned char* input, int input_size,
		   unsigned char* output, int output_size){
	unsigned char *pos=input;

	for(int i=0; i<output_size; i++){
		sscanf(pos, "%2hhx", &output[i]);
		pos +=2*sizeof(char);
	}
	/*
	//test results
	for(int i=0; i<output_size; i++)
		printf("%02x ", output[i]);
	printf("\n");
	*/
}

void tohex_in_place(unsigned char* input, int input_size){
	unsigned char *pos=input;

	for(int i=0; i<input_size/2; i++){
		sscanf(pos, "%2hhx", &input[i]);
		pos +=2*sizeof(char);
	}
	input[input_size]=0x0;
}

void xor_to_output(unsigned char* input1, unsigned char* input2,
				   unsigned char* output, int arr_length){

	for(int i=0; i<arr_length; i++)
		output[i]=input1[i]^input2[i];
}

void xor_in_place(unsigned char* input1, unsigned char* input2,
				  int arr_length){

	for(int i=0; i<arr_length;i++)
		input1[i]=input1[i]^input2[i];
}
