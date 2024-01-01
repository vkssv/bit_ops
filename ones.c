#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main() {
    int x;

    printf("Enter any integer\t");
    scanf("%d", &x);
    

    printf("Binary repr of %d is :", x);
    decToBinary(x);
    printf("One's compliment of %d is %d\n", x, ~x);
    decToBinary(~x);

    return 0;
}

void decToBinary(int n) {
    int bin_num[100];
    memset(bin_num, 0, sizeof(bin_num));
    printf(">>> %d\n", n);
    unsigned char negative = 0;
    
    int i = 0;
    int j = 0;

    if (n < 1) {
        n *= -1;
        negative = 1;
        //data = UINT_MAX - n + 1; // store in mem
    };

    printf(">>>data %d\n", n);
    

    while (n > 0) {
        printf(">>>modulo %d\n", n % 2);
        bin_num[i] = n % 2;
        i++;
        n /= 2;
        printf(">>>new data %d, i=%d\n", n, i);
    }

    if (negative) {
        for (j = i - 1; j>=0; j--) {
            printf("num=%d, flipped=%d", bin_num[j], UINT_MAX - bin_num[j]);
        }
    } else {
        for (j = i - 1; j>=0; j--) {
            printf(" %d", bin_num[j]);
        }
    }
   
    printf("\n");

    return;
}