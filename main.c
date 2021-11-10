#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca.h"

unsigned char rule110(struct ca_data *data, int index)
{

    if (data->cadata[index - 1][0] == 1 && data->cadata[index][0] == 1 && data->cadata[index + 1][0] == 1)
        return 0;
    if (data->cadata[index - 1][0] == 1 && data->cadata[index][0] == 1 && data->cadata[index + 1][0] == 0)
        return 1;
    if (data->cadata[index - 1][0] == 1 && data->cadata[index][0] == 0 && data->cadata[index + 1][0] == 1)
        return 1;
    if (data->cadata[index - 1][0] == 1 && data->cadata[index][0] == 0 && data->cadata[index + 1][0] == 0)
        return 0;
    if (data->cadata[index - 1][0] == 0 && data->cadata[index][0] == 1 && data->cadata[index + 1][0] == 1)
        return 1;
    if (data->cadata[index - 1][0] == 0 && data->cadata[index][0] == 1 && data->cadata[index + 1][0] == 0)
        return 1;
    if (data->cadata[index - 1][0] == 0 && data->cadata[index][0] == 0 && data->cadata[index + 1][0] == 1)
        return 1;
    if (data->cadata[index - 1][0] == 0 && data->cadata[index][0] == 0 && data->cadata[index + 1][0] == 0)
        return 0;
    return data->cadata[index][0];
}

unsigned char CGOL(struct ca_data *ca, int x, int y)
{
    ca->wrap = 1;
    return 1;
}

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
    fscanf(f, "%d %d", &h, &w);
    printf("Num rows: %d\nNum cols: %d\n", h, w);
    *str = malloc(sizeof(unsigned char) * w);

    ca_data *ca;

    if (dims == 1)
    {
        ca = create1DCA(w, '0');
        for (int x = 0; x < w; x++)
        {
            if (fscanf(f, "%s ", str) != EOF)
                printf("%s ", str);
            else
                break;
        }
        printf("\n");
    }
    else
    {
        ca = create2DCA(w, h, '0');

        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                if (fscanf(f, "%s ", str) != EOF)
                    printf("%s ", str);
                else
                    break;
            }
            printf("\n");
        }
    }
    fclose(f);
}
