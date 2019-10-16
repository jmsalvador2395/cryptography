#include <stdlib.h>
#include "bystringspp.h"

#ifndef _BYTE_STRINGS_PP_H_
#define _BYTE_STRINGS_PP_H

void tohex(unsigned char* input, int input_size, unsigned char* output, int output_size);

void tohex_in_place(unsigned char* input, int input_size);

#endif
