#include <stdio.h>
#include <stdlib.h> // for malloc
#include <stdint.h>

 
int ex1(void)
{
    unsigned char i = 0x80;
    printf("%d\n", i << 1); //

    return 0;
} // result is 256 
// unsigned char a;
// a = 0;
// printf("%d\n", a - 1); 
// First of all, when you pass an integer argument smaller than int to a variadic
// function (like printf) then it's automatically promoted to an int.
// Secondly, when you use arithmetic, smaller integer types again are promoted to int.

int ex2(void) {
    int n = 1L; // expression 1L has type long, int is expected
    printf("size of n now is %zu\n", sizeof(n)); //
    n = 2.1; // expression 2.1 has type double, int is expected
    printf("n now is %d\n", n); //
    char *p = malloc(10); // expression malloc(10) has type void*, char* is expected
    printf("p now is %d\n", *p); //
}

int ex3(void) {
    unsigned int a = 10;
    a = ~a;
    printf(">>> %d\n", a);
}

int ex4(void) {
    int8_t x = -1;
    printf("1byte negative -1 before shift: %x\n", x); // %hhi does not work ?
    printf("1byte negative -1 after shift: %x\n", x >> 1); // printf always completes up to 4byte int
    int16_t y = -1;
    printf("2bytes negative -1 before shift %x\n", y);
    printf("2bytes negative -1 after shift %x\n", y >> 1);
    int32_t z = -1;
    printf("4bytes negative -1 before shift %x\n", z);
    printf("2bytes negative -1 after shift %x\n", z >> 1);
}

int ex5(void) {

	int a = 5;
	int b = 7;
	
	int result = b & ((a-b) >> 31) | a & (~(a-b) >> 31);

    printf("((a-b) >> 31)=%d\n", (a-b) >> 31);
    printf("(~(a-b) >> 31)=%d\n", (~(a-b) >> 31));
	printf("%d\n", result);
	
	return 0;

}


int main() {
    ex1();
    ex2();
    ex3();
    ex4();
    ex5();

    return 0;

}