#ifndef _BYTE_STRINGS_H_
#define _BYTE_STRINGS_H_

void tohex(unsigned char* input, int input_size, unsigned char* output, int output_size);

void xor_to_output(unsigned char* input1, unsigned char* input2, unsigned char* output, int arr_length);

void xor_in_place(unsigned char* input1, unsigned char* input2, int arr_length);
#endif
