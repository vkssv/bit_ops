#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>




int main(void) {


    int x;
    printf("Input any integer:\n");

    
    scanf("%d", &x);

    char str[15] = {0};
    printf("init str: '%s'\n", str);
    snprintf(str, 15, "%d", x);
    printf("str: %s\n", str);


    char str1[] = "10 555";
    char *next_pos;

    intmax_t val1 = strtoimax(str1, &next_pos, 10); // inttypes.h
    intmax_t val2 = strtoimax(next_pos, &next_pos, 10);

    printf("val1=%ld, val2=%ld\n", val1, val2);

    long int y = strtol(str1, &next_pos, 10); // stdlib.h
    long int z = strtol(next_pos, &next_pos, 10);
    printf("y=%ld, z=%ld\n", y, z);
    


    return 0;
}


