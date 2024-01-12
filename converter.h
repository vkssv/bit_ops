#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdint.h>

#define STR32 33
#define USR_INPUT 3 // char + '\n' + ''

void print_bin(uint32_t num);

int bin_to_dec(char *bin_str);

void reverse_string(char* _array);

extern int X = 5;

#endif
