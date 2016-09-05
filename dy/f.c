#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(argc, argv)
int argc;
char **argv;
{
    int file = open("outfile",
        O_CREAT | O_RDWR | O_APPEND,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
    if (file < 0)
    {
        fprintf(stderr, "open error: %d [%s]\n", errno, strerror(errno));
        exit(1);
    }
    dup2(file,1);
    close(file);
    int ret = execl("/bin/ls","ls","-1",(char *)0);

    return 0;
}