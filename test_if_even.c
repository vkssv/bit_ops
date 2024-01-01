#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

int main() {
    int32_t x;

    printf("Enter any integer\t");
    scanf("%d", &x);
    
    printf("masked %d\n", x & 1);
    

    if ((x & 1) == 0)
        printf("Number is even: %d\n", x);
    else
        printf("Number is odd: %d\n", x);


    return 0;
}