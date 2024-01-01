#include <stdio.h>
#include <string.h>  /* to calculate str length */
#include <stdint.h>

#define STR32 33

void print_bin(int num);
void print_dec(char *bin_str);

void reverse_string(char* _array);


int main(int argc, char *argv[]) {
    printf("The binary value of 111111 is: \n");
    print_bin(111111);
    printf("\n");

    char bin_str[STR32] = {0}; // make it large enough to hold an int32_t + '\0'
    scanf("%s", bin_str);

    return 0;

}


int bin_to_dec(char *bin_str) {
    int dec_num = 0;
    int i = 0;

    reverse_string(bin_str);
    printf("+++ reversed string %s\n", bin_str);
    
    while(*bin_str != '\0') {
        dec_num +=(*bin_str)*(1 << i++);
    }

    printf("+++ dec num = %d\n", dec_num);

    return dec_num;


}

void print_bin(int num) {
    char bin_string[65] = {0};
    int i = 0;
    const char zero = '0';

    do {
        bin_string[i++] = (num % 2) + zero;
    } while (num /= 2);

    bin_string[i] = '\0';
    reverse_string(bin_string);
    printf("+++ %s\n", bin_string);
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





