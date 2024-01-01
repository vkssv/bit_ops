#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd_s, fd_t;
    char ch;

    fd_s = open("loveletter.txt", O_RDONLY);
    fd_t = open("target.txt", O_WRONLY | O_CREAT | O_TRUNC);
    printf("Source file = %d, target_file=%d", fd_s, fd_t);

    //if (!fd_s || !fd_t) {
    //    printf("Can't open file!\n");
    //    exit(1);
    //}

    //while((ch = getc(fd_s) != EOF))
    //    putc(~ch, fd_t);

    close(fd_s);
    close(fd_t);


    return 0;
}