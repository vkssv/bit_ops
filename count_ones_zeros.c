#include <stdio.h>
#include <string.h>  /* to calculate str length */
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include "converter.h"


static void count_ones_zeros(uint32_t num) {

    uint32_t mask = 1 << sizeof(uint32_t) * CHAR_BIT - 1;
    uint8_t ones = 0;
    uint8_t zeros = 0;
    int i;

    for (i=0; i < sizeof(uint32_t) * CHAR_BIT; i++) {
        num & mask ? ones++ : zeros++;
        mask >>= 1;
    };
    printf("ONES: %d; ZEROS: %d\n", ones, zeros);
};




int main(void) {

    
    uint32_t x = 0XFFFAAFFF;
    print_bin(x);
    count_ones_zeros(x);

    return 0;
};
