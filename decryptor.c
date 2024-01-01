#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    FILE *fd_s, *fd_t;
    char ch;

    fd_s = fopen("target.txt", "r");
    fd_t = fopen("decrypted.txt", "w");

    if (!fd_s || !fd_t) {
        printf("Can't open file!\n");
        exit(1);
    }

    while((ch = getc(fd_s) != EOF))
        putc(ch*(-1)-1, fd_t);

    fclose(fd_s);
    fclose(fd_t);


    return 0;
}