#include <stdio.h>
#include <stdlib.h>
#include <bits/wordsize.h>
#include <stdint.h>
#include "converter.h"


uint32_t double_it(uint32_t _x);

uint32_t ones_complement(uint32_t _x);
uint32_t twos_complement(uint32_t _x);




uint32_t double_it(uint32_t _x) {

    return _x << 1;
};

uint32_t ones_complement(uint32_t _x) {
    // return ~_x;
#if __WORDSIZE == 64
    return _x ^ 0xffffffffffffffff;
#endif

#if __WORDSIZE == 32
    return _x ^ 0xffffffff;
#endif

    return 0;
}

uint32_t twos_complement(uint32_t _x) {
    //return ~_x + 1;

    return ones_complement(_x) + 1;
}

int main(int argc, char* argv[]) {
    uint32_t x = 8;

    printf("%d in binary is: \n", x);
    print_bin(x);
    printf("\n");

    printf("One's compliment of %d is %d\n", x, ~x);
    print_bin(ones_complement(x));
    printf("Two's compliment of %d is %d\n", x, twos_complement(x));
    print_bin(twos_complement(x));
    
    printf("Printf >> double_it %d=%d\n", x, double_it(x));
    print_bin(double_it(x));
    printf("Printf %d\n", x);


    printf("\n");

    return 0;

};