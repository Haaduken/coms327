#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca.h"

int main(int argc, char **argv)
{
    int dims = -1;
    int h = 0;
    int w = 0;
    FILE *f;
    if (!strcmp(argv[1], "1"))
    {
        dims = 1;
        h = 1;
    }
    else if (!strcmp(argv[1], "2"))
        dims = 2;
    else
    {
        printf("Invalid input: %s\n", argv[1]);
        exit(1);
    }
    f = fopen(argv[2], "r");
    if (f == NULL)
    {
        perror("unable to open file!\n");
        exit(1);
    }

    unsigned char *str = malloc(sizeof(unsigned char) * 6);
    int numElements = 0;
    fscanf(f, "%d %d", &h, &w);
    printf("Num rows: %d\nNum cols: %d\n", h, w);
    *str = malloc(sizeof(unsigned char) * w);
    // while (fscanf(f, "%[^\n ] ", str) != EOF && numElements != 2)
    // {
    //     // printf("%s\n", str);

    // }
}
