#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 65;
    int y;

    printf("x = %d\n", x);

    // test if fifth bit is set
    y = x & 32;

    if (y == 0)
        printf("The fifth bit is OFF\n");
    else
        printf("The fifth bit is ON\n");
    
    y = x & 64;

    if (y == 0)
        printf("The sixth bit is OFF\n");
    else
        printf("The sixth bit is ON\n");


    // clearing a bit
    // clear the second bit
    unsigned int c = 7;                // |0|0|0|0| |0|1|1|1|
    unsigned int mask_clear = 0xFD;    // |1|1|1|1| |1|1|0|1|  ones at other positions than second keep intact all other bits !!
    c = c & mask_clear;
    printf("With cleared bit the value is 0x%x\n", c);

    // extract right-most six bits

    unsigned int a = 0x6db7;
    unsigned int b;

    /* a = |0|1|1|0|  |1|1|0|1|  |1|0|1|1|  |0|1|1|1|
    *          6          d          b          7 
    * 
    * mask to extract:
    *      |0|0|0|0|  |0|0|0|0|  |0|0|1|1|  |1|1|1|1|
    *                                3          F       
    * &:
    *      |0|0|0|0|  |0|0|0|0|  |0|0|1|1|  |0|1|1|1|
    *                                3          7
    */

    b = a & 0x3f;
    printf("Extracted bits are 0x%x\n", b);

    return 0;
}