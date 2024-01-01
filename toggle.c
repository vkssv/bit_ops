#include <stdio.h>
#include <stdlib.h>

int main() {
    int b = 50;
    printf("Orig value of b is %d\n", b);
    
    b ^= 12;
    printf("First XORed value of b is %d\n", b);

    b ^= 12;
    printf("Second XORed value of b is %d\n", b);

    return 0;

}




