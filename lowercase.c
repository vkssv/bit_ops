#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main() {
    char x;

    printf("Enter char\t");
    scanf("%c", &x);

    unsigned int char_mask = 1 << 5;
    printf("lowered char is : %c\n", (x ^= char_mask));
    printf("uppered char is : %c\n", (x ^= char_mask));



    return 0;
}