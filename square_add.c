#include <stdio.h>

int square(int x);
int add(int x, int y);

#define UINT unsigned int


int main(void) {

    char ch = 0;
    

    UINT x = 0;
    do {
        printf("Enter a value to square:\n");
        scanf("%u", &x);
        fseek(stdin, 0, 0);
        printf("\n%d squared is %d\n", x, square(x));
        getchar();
        fseek(stdin, 0, 0);
        //system("clear"); 
    } while (ch !='q');

    return 0;

    return 0;
};


int square(int x) {
    int i;
    int temp = x;
    for (i = 1; i < temp; i++) {
        x = add(x, temp);
    }

    return x;
}

int add(int x, int y) {

    int carry = 1;

    while(carry != 0) {
        carry = x & y; // 1. check if there will be a new carry (so even after adding a current carry)
        x = x ^ y; // basically addition without taking carry in account, adds two operands
        y = carry << 1; // now before adding a carry set it up as an new second operand value
    }

    return x;
}


