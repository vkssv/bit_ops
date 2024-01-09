#include <stdio.h>
#include <stdlib.h>
#include <bits/wordsize.h>
#include <stdint.h>
#include "converter.h"


#ifndef UINT
#define UINT unsigned int
#endif

UINT double_it(UINT _x);

UINT ones_complement(UINT _x);
UINT twos_complement(UINT _x);




UINT double_it(UINT _x) {

    return _x << 1;
};

UINT ones_complement(UINT _x) {
    // return ~_x;
#if __WORDSIZE == 64
    return _x ^ 0xffffffffffffffff;
#endif

#if __WORDSIZE == 32
    return _x ^ 0xffffffff;
#endif

    return 0;
}

UINT twos_complement(UINT _x) {
    //return ~_x + 1;

    return ones_complement(_x) | 1;
}

int main(int argc, char* argv[]) {
    UINT x = 8;
    UINT j = 0;

    //printf("%d in binary is: ", x);
    //print_bin(x);
    //printf("\n");

    //printf("One's compliment of %d is %d", x, ~x);
    //print_bin(ones_complement(x));
    j = double_it(x);
    printf("Printf >> double_it %d=%d", x, double_it(x));
    print_bin(double_it(x));
    print_bin(double_it(x));
    printf("Printf %d\n", x);


    printf("\n");

    return 0;

};