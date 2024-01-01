#include<stdio.h>
#include <stdlib.h> // for malloc

 
int ex1()
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

int ex2() {
    int n = 1L; // expression 1L has type long, int is expected
    printf("size of n now is %zu\n", sizeof(n)); //
    n = 2.1; // expression 2.1 has type double, int is expected
    printf("n now is %d\n", n); //
    char *p = malloc(10); // expression malloc(10) has type void*, char* is expected
    printf("p now is %d\n", *p); //
}

int ex3() {
    unsigned int a = 10;
    a = ~a;
    printf(">>> %d\n", a);
}


int main() {
    ex1();
    ex2();
    ex3();



    return 0;

}