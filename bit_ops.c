#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "converter.h"


static bool check_alternate(int32_t x) {
    print_bin(x);


}

int main(int argc, char *argv[]) {

    int32_t x;

    printf("Enter any integer\t");
    scanf("%d", &x);
    check_alternate(x);
    



    return 0;
}


