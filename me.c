#include "get_next_line.h"
#include "stdio.h"
#include "unistd.h"

int main (void)
{
    int fd;
    char *texticulo;
    int i;

    i = 1;
    fd = open("me.txt", O_RDONLY);

    while (i)
    {
    texticulo = get_next_line(fd);
    printf("&%s|",texticulo);
    if (!texticulo)
        i = 0;
    free(texticulo);
    texticulo = 0;
    }
    close(fd);
}