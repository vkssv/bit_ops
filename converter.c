#include <stdio.h>
#include <string.h>  /* to calculate str length */
#include <stdlib.h>
#include <limits.h>
#include "converter.h"

/*
int main(int argc, char *argv[]) {
    
    /*
    char ch[USR_INPUT] = {0}; // for sentinel char + '\n' added as ICANON | ECHO flags are set in struct termios with tty attrs by default (canonical mode)
    This depends on your OS, if you are in a UNIX like environment the ICANON flag is enabled by default, 
    * so input is buffered until the next '\n' or EOF. By disabling the canonical mode you will get the characters 
    * immediately, i.e. |char| instead of |char|\n| or |char|EOF| or |char|EOL|.
    * *ICANON normally takes care that one line at a time will be processed
    * that means it will return if it sees a "\n" or an EOF or an EOL: 
    * newt.c_lflag &= ~(ICANON | ECHO); => carefull, this also disables EOF for non-canonical mode;
    * https://stackoverflow.com/questions/1798511/how-to-avoid-pressing-enter-with-getchar-for-reading-a-single-character-only          
    
    char bin_str[STR32] = {0}; // make it large enough to hold an int32_t + '\0'

    system("clear"); 
    do {

        printf("Enter the binary number to be converted to decimal:\n");
        fgets(bin_str, STR32, stdin);
        printf("Entered line: <%s>>\n", bin_str);
        bin_str[strlen(bin_str)-1] = '\0';
        printf("Corrected line: <%s>>\n", bin_str);
        printf("+++ dec num is %d\n", bin_to_dec(bin_str));
        printf("\n\nPress 'q' to quit... OR \nPress ANY key to continue...\n");
        fgets(ch, USR_INPUT, stdin);
        fseek(stdin, 0, SEEK_END); // successful call to the fseek() function clears the end-of-file indicator for the stream and undoes any effects of the ungetc(3)
    } while ( ch[0] != 'q' );

    //printf("The binary value of 111111 is: \n");
    //print_bin(111111);
    //printf("\n");
    //scanf("%s", bin_str);
    return 0;
    
    unsigned x = 7;
    print_bin(x);

    return 0;
}
*/

int bin_to_dec(char *bin_str) {
    int dec_num = 0;
    int i = 0;

    reverse_string(bin_str);
    printf("+++ reversed string %s\n", bin_str);

    while(*bin_str != '\0') {
        dec_num += (*bin_str - '0')*(1 << i++);
        bin_str++;
    }

    return dec_num;

}

void print_bin(uint32_t num) {
    
    unsigned int i = 0;
    uint32_t mask = 1 << sizeof(uint32_t) * CHAR_BIT - 1;

    for(i = 0; i < sizeof(unsigned int) * CHAR_BIT; i++) {
        printf("%c", num & mask ? '1' : '0');
        if ((i + 1) % 8 == 0) {
            printf(" ");
        };
        
        num <<= 1;

    }
    printf("\n");
    //char bin_string[33] = "00000000000000000000000000000000"; //32 + '\0'
    //int i = 0;
    //const char zero = '0';
    //bin_string[32] = '\0'; 

    //do {
    //    bin_string[i++] = (num % 2) + zero;
    //} while (num = num << 1);

    //reverse_string(bin_string);
    //printf("+++ %s\n", bin_string);
}



/* pointer arithmetics */
//void reverse_string(char* _array) {
//    char temp;
//    int len = strlen(_array) - 1; // ?
//    printf("len is %d", len);
//    int i = len;
 
//    while(i != len >> 1) {
//        temp = *_array;
//        *_array = *(_array+i);
//        *(_array+i) = temp;
//        i--;
//        _array++;
//    }
//}
 


void reverse_string(char* _array) {
    char temp = 0;
    int last_index = strlen(_array) - 1;
    int first_index = 0;

    while (first_index < last_index) {
        if ( _array[first_index] != _array[last_index]){
            temp = _array[first_index];
            _array[first_index] = _array[last_index];
            _array[last_index] = temp;
        }
        first_index++;
        last_index--;
    }
}





