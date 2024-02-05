#include<stdio.h>


int func(int* a) {
    printf("%zu\n", sizeof(a));
}
 
int main()
{
    unsigned char i = 0x80;
    printf("%d\n", i << 3);

    int array[5] = {1,2,3,4,5};
    printf("%s: %zu\n", __func__, sizeof(array));
    func(array);

 
    int Arr[] = { 1, 2, 3, 4, 5, 6 };
    // variable to store the size of Arr
    int length = *(&Arr + 1) - Arr;


    printf( "&Arr + 1=%p, *(&Arr + 1)=%p, Arr=%p\n", (&Arr + 1), *(&Arr + 1), Arr);
    printf( "Number of elements in Arr[] is: %d\n", length);


    return 0;
}
