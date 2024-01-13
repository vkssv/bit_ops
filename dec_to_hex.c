#include <stdio.h>
#include <string.h>
#include "converter.h"

#define UINT unsigned int
#define MAX_HEX_ARRAY_LEN 128

char *dec_to_hex(char *hex_str, UINT dec_num);
int X;

int main(int argc, char *argv[]) {

    char ch = 0;
    char hex_str[MAX_HEX_ARRAY_LEN] = {0};
    
    printf(">>X=%d", X);
    UINT x = 0;
    do {
        printf("Enter a positive dec value to convert to HEX:\n");
        scanf("%u", &x);
        fseek(stdin, 0, 0);
        printf("\n%d is 0x%s in HEX\n", x, dec_to_hex(hex_str, x));
        getchar();
        fseek(stdin, 0, 0);
        //system("clear"); 
    } while (ch !='q');

    return 0;
}

char *dec_to_hex(char *hex_str, UINT dec_num) {

    //char *ptemp;
    const int MAX_CHUNK_LEN = 9;
    char *start = hex_str;

    do {
        snprintf(hex_str++, MAX_CHUNK_LEN, "%X", (dec_num % 16));
        
    } while (dec_num >>= 4);

    reverse_string(start);

    return start;
};