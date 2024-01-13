#include <stdio.h>
#include <string.h>  /* to calculate str length */
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

void print_bin(int32_t num);


int main(int argc, char *argv[]) {
    
    
    int32_t x = -7;
    print_bin(x);
    print_bin(-2); 
    // 11111111 11111111 11111111 11111110
    int32_t z = -2 >> 31; // sign is keept ! and freed space filled with 1 and not with zeros !! = -1
    // 11111111 11111111 11111111 11111111
    print_bin(z);

    int32_t y = (~(-2) >> 31);
    print_bin(y);
    return 0;
}

void print_bin(int32_t num) {
    
    unsigned int i = 0;
    //printf("sizeof(unsigned int) * CHAR_BIT - 1=%zu\n", sizeof(uint32_t) * 8 - 1); // 31
    uint32_t mask = 1 << sizeof(uint32_t) * CHAR_BIT - 1;
    //uint32_t mask = 1 << 31;

    for(i = 0; i < sizeof(unsigned int) * CHAR_BIT; i++) {
        //printf(">>> num=%d, i=%d, mask=%d\n", num, i, mask);
        printf("%c", num & mask ? '1' : '0');
        if ((i + 1) % 8 == 0) {
            printf(" ");
        };
        
        num <<= 1;

    }
    //while (i < sizeof(uint32_t) * 8) {
        //
        
    //}
    printf("\n");
    //char bin_string[33] = "00000000000000000000000000000000"; //32 + '\0'
    //int i = 0;
    //const char zero = '0';
    //bin_string[32] = '\0'; 

    //do {
    //    bin_string[i++] = (num % 2) + zero;
    //} while (num = num << 1);

    //reverse_string(bin_string);
    //printf("+++ %s\n", bin_string);
}



/* pointer arithmetics */
//void reverse_string(char* _array) {
//    char temp;
//    int len = strlen(_array) - 1; // ?
//    printf("len is %d", len);
//    int i = len;
 
//    while(i != len >> 1) {
//        temp = *_array;
//        *_array = *(_array+i);
//        *(_array+i) = temp;
//        i--;
//        _array++;
//    }
//}
 