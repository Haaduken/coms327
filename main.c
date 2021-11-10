#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca.h"

unsigned char rule110(struct ca_data *data, int index)
{
    if (data->cadata[0][index - 1] == 1 && data->cadata[0][index] == 1 && data->cadata[0][index + 1] == 1)
        return 0;
    if (data->cadata[0][index - 1] == 1 && data->cadata[0][index] == 1 && data->cadata[0][index + 1] == 0)
        return 1;
    if (data->cadata[0][index - 1] == 1 && data->cadata[0][index] == 0 && data->cadata[0][index + 1] == 1)
        return 1;
    if (data->cadata[0][index - 1] == 1 && data->cadata[0][index] == 0 && data->cadata[0][index + 1] == 0)
        return 0;
    if (data->cadata[0][index - 1] == 0 && data->cadata[0][index] == 1 && data->cadata[0][index + 1] == 1)
        return 1;
    if (data->cadata[0][index - 1] == 0 && data->cadata[0][index] == 1 && data->cadata[0][index + 1] == 0)
        return 1;
    if (data->cadata[0][index - 1] == 0 && data->cadata[0][index] == 0 && data->cadata[0][index + 1] == 1)
        return 1;
    if (data->cadata[0][index - 1] == 0 && data->cadata[0][index] == 0 && data->cadata[0][index + 1] == 0)
        return 0;
    return data->cadata[0][index];
}

unsigned char CGOL(struct ca_data *ca, int x, int y)
{
    int nextX = (x + 1 + ca->width) % ca->width;
    int lastX = (x - 1 + ca->width) % ca->width;
    int nextY = (y + 1 + ca->height) % ca->height;
    int lastY = (y - 1 + ca->height) % ca->height;
    int souls = 0;
    // printf("%d, %d, %d, %d\n", nextX, lastX, nextY, lastY);
    if (ca->cadata[lastY][lastX] == 1)
        souls++;
    if (ca->cadata[lastY][x] == 1)
        souls++;
    if (ca->cadata[lastY][nextX] == 1)
        souls++;
    if (ca->cadata[y][lastX] == 1)
        souls++;
    if (ca->cadata[y][nextX] == 1)
        souls++;
    if (ca->cadata[nextY][lastX] == 1)
        souls++;
    if (ca->cadata[nextY][x] == 1)
        souls++;
    if (ca->cadata[nextY][nextX] == 1)
        souls++;
    // printf("%d\n", ca->cadata[nextY][nextX]);
    if (ca->cadata[y][x] == 1 && souls < 2)
    {
        // printf("0\n");
        return 0;
    }
    else if (ca->cadata[y][x] == 1 && souls > 3)
    {
        // printf("2\n");
        return 0;
    }
    else if (ca->cadata[y][x] == 0 && souls == 3)
    {
        // printf("3\n");
        return 1;
    }
    else
    {
        // printf("4\n");
        return ca->cadata[y][x];
    }
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
    free(str);
    unsigned int state;
    ca_data *ca;
    if (dims == 1)
    {
        // printf("Create 1DCA\n");

        ca = create1DCA(w, '0');
        ca->dimension = dims;
        ca->qstate = 0;
        for (int x = 0; x < w; x++)
        {
            if (fscanf(f, "%u", &state) != EOF)
            {
                set1DCACell(ca, x, state);
            }
            else
                break;
        }

        displayCA(ca);
        while (1)
        {
            char check = getchar();
            if (check == '\n')
            {
                step1DCA(ca, rule110);
                displayCA(ca);
            }
            else if (check != '\n')
                break;
        }
    }
    else
    {
        ca = create2DCA(w, h, 0);
        ca->dimension = dims;
        ca->wrap = 1;
        ca->qstate = 0;
        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                if (fscanf(f, "%u", &state) != EOF)
                {
                    set2DCACell(ca, x, y, state);
                }
                else
                    break;
            }
        }

        displayCA(ca);
        while (1)
        {
            char check = getchar();
            if (check == '\n')
            {
                step2DCA(ca, CGOL);
                displayCA(ca);
            }
            else if (check != '\n')
                break;
        }
    }
    fclose(f);
}
