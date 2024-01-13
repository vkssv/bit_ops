#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "converter.h"


/*Write a C program to check whether the given integer has an alternate bit pattern or not. 
* For example the integer 42 has got alternate bit pattern as 101010 where as the integer 
* 364 has got bit pattern as 1 0110 1100
*/

/* not optimal but fan */
static int check_alternate1(int32_t x) {
    
    uint32_t mask = 0;
    int pos;
    int j = 2;

    for ( pos = 0; pos < sizeof(int32_t)* CHAR_BIT; pos++ ) {
        if (pos % 2 == 1) {
            mask |= j;
            j <<= 2;
        }
    }
    print_bin(x);
    print_bin(mask); 

    for ( pos = 0; pos < sizeof(int32_t)* CHAR_BIT; pos++ ) {
        if ((x & mask) == mask) {
            printf("Alternate\n!");
            return 1;
        }
        mask >>= 1;  
    }

    return 0;

}

static int check_alternate(int32_t x) {
    
    uint32_t mask;
    int pos;

    if (x == 0) {
        return 0;
    }
    if (x > 0)
        mask = 1;
    else
        mask = UINT32_MAX;

    for ( pos = 0; pos < sizeof(uint32_t)* CHAR_BIT; pos++ ) {
        
        print_bin(mask);
        print_bin(x);
        
        /* more readable, believe that GCC optimize this */

        if ((x > 0) && ((x & mask) == x)) {
            printf("Alternate \n!");
            return 1;
        }
        if ((x < 0) && ((x & mask) == mask)) {
            printf("Alternate \n!");
            return 1;
        }
       
        mask <<= 1;
        if (pos % 2 == 1) {
            mask++; /* to avoid "...100"*/
        }
    }

    return 0;
}

/*Write a C program that uses function to return Most Significant Bit of an unsigned integer. 
* For example position of MSB of 5 is 2 since bit pattern is 101 and MSB of 
* 475 is 8 since bit pattern is 1 1101 1011
*/
static int msb_position(uint32_t x) {

    uint32_t mask = 1 << sizeof(uint32_t)*CHAR_BIT - 1;
    int pos;

    for (pos=0; pos < sizeof(uint32_t)*CHAR_BIT; pos++) {
        if ((x & mask) == mask ) {
            return sizeof(uint32_t)*CHAR_BIT - 1 - pos;
        };
        mask >>=1;
    };

    return -EINVAL;
}

/* Write a C Program to check if all the bits of a given integer is one i.e. 
* whether all bits are ON. For example 31 has got bit pattern of 1 1111.
*/
static int all_is_on(int32_t x) {
    int32_t mask;
    int pos;
    
    if (x == 0) {
        return 0;
    };

    if (x > 0) {
        mask = INT32_MAX;
    } else
        mask = -1; // notes to self: when we shift its negative so it is always filled with '1'

    for(pos=0; pos < sizeof(int32_t)* CHAR_BIT; pos++) {
        print_bin(mask);
        print_bin(x);
        if ((x & mask) == mask ) {
            return 1;
        };
        mask >>= 1;
    }

    return 0;
}

/*
* Write a C program to input any number from user and check whether 
* nth bit of the given number is set ON or OFF.
*/
static int check_bit(int32_t x, uint8_t pos) {
    int32_t mask = 1 << pos;

    print_bin(mask);
    print_bin(x);
    if ((x & mask) == mask) {
        return 1;
    }

    return 0;

}

static void rotate_left(uint32_t *x) {
    printf("left shift\n");
    print_bin(*x);
    
    if ((*x & 1) == 1) {
        *x >>= 1;
        print_bin(*x);
        *x |= (1 << sizeof(*x) * CHAR_BIT - 1);
        print_bin(*x);
    } else {
        *x >>= 1;
        print_bin(*x);
    }
}

static void rotate_right(uint32_t *x) {
    uint32_t mask = 1 << sizeof(*x) * CHAR_BIT - 1;
    printf("right shift\n");
    print_bin(*x);
    if ((*x & mask) == mask) {
        *x <<= 1;
        print_bin(*x);
        *x |= 1;
        print_bin(*x);
    } else  {
        *x <<= 1;
        print_bin(*x);
    }
}

static void rotate_bits(uint32_t x, int left) {

    int i;
    int msb_pos = msb_position(x);
    uint32_t mask_last = 1;

    printf(">>>msb=%d\n", msb_pos);

    int end = msb_position(x);
    if (left)
        end = sizeof(x) * CHAR_BIT - 1;
    
    for(i = 0; i <= end; i++) {
        printf(">>> i=%d, end=%d\n", i, end);
        

        if (left)
            rotate_right(&x);
        else
            rotate_left(&x);
    }
    print_bin(x);
}


int main(int argc, char *argv[]) {

    int32_t x, y;
    uint8_t pos;

    printf("Enter any integer\t");
    scanf("%d", &x);
    print_bin(x);
    if (check_alternate(x)) {
        printf(">>> Alternate !");
    }
    printf("\n");

    printf("Enter any positive int\t");
    scanf("%d", &x);
    print_bin(x);
    printf("MSB pos is: %d\n", msb_position(x));
    
    printf("Enter any integer\t");
    scanf("%d", &x);
    print_bin(x);
    printf("All bits is set: %s\n", all_is_on(x) ? "yes": "no");
    
    printf("Enter position, start from 0\t");
    scanf("%hhd", &pos);
    print_bin(x);
    printf("%d-th bits is : %s\n", pos, check_bit(x, pos) ? "on": "off");
    
    printf("Enter any positive int\t");
    scanf("%d", &x);
    y = x;
    printf("Rotate left\n");
    rotate_bits(x, 0);
    print_bin(y);
    printf("\n");
    printf("\n");
    printf("Rotate right\n");
    rotate_bits(x, 1);
    print_bin(y);

    return 0;
}


