#include<stdio.h>


int func(int* a) {
    printf("%zu\n", sizeof(a));
}
 
int main()
{
    unsigned char i = 0x80;
    printf("%d\n", i << 3);

    int array[5] = {1,2,3,4,5};
    func(array);

    return 0;
}
