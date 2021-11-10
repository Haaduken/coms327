#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca.h"

/**
 *  @param ca_data struct to grab array from and output
 */
void displayCA(struct ca_data *data)
{
    for (int i = 0; i < data->height; i++)
    {
        for (int j = 0; j < data->width; j++)
            printf("%d ", data->cadata[j][i]);
        printf("\n");
    }
    printf("\n");
}

/**
 * @param data which struct to read and write to
 * @param x where to write to in data's cadata width
 * @param setVal what to write in data's cadata width
 * @return 0 on fail, 1 on successful writing
 */
int set1DCACell(struct ca_data *data, unsigned int x, unsigned char setVal)
{
    if (x > data->width)
        return 0;
    data->cadata[x][data->height - 1] = setVal;
    return 1;
}

/**
 * @param data which struct to read and write to
 * @param x where to write to in data's cadata width
 * @param y where to write to in data's cadata height
 * @param setVal what to write in data's cadata width and height
 * @return 0 on fail, 1 on successful writing
 */
int set2DCACell(struct ca_data *ca, unsigned int x, unsigned int y, unsigned char state)
{
    if (x > ca->width || y > ca->height)
        return 0;
    ca->cadata[x][y] = state;
    return 1;
}

/**
 * @param data which struct to initialize
 */
void initCA(struct ca_data *data, int initVal)
{
    memset(data->cadata, (int)(initVal), sizeof(ca_data));
}

/**
 * @param numCells how large the array in a newly created ca_data should be
 * @param initialVal what the starting state of it should be
 */
struct ca_data *create1DCA(int numCells, unsigned char initialVal)
{
    ca_data *data = malloc(sizeof(ca_data));
    data->height = 1;
    data->width = numCells;
    data->qstate = initialVal;
    data->cadata = malloc(sizeof(unsigned char) * data->height * data->width);
    initCA(data, data->qstate);
    for (int x = 0; x < data->width; x++)
    {
        set1DCACell(data, x, data->qstate);
    }
    return data;
}

struct ca_data *create2DCA(int w, int h, unsigned char qstate)
{
    ca_data *data = malloc(sizeof(ca_data));
    data->height = h;
    data->width = w;
    data->qstate = qstate;
    data->cadata = malloc(sizeof(unsigned char) * data->height * data->width);
    initCA(data, data->qstate);
    for (int y = 0; y < data->height; y++)
    {
        for (int x = 0; x < data->width; x++)
        {
            set2DCACell(data, x, y, data->qstate);
        }
    }
    return data;
}

/**
 * @param data which struct to step through
 * @param rule function pointer to throw data into
 */
void step1DCA(struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int))
{
    // ca->wrap = edgeCase;
    //create a padded copy of data (+1 on each side) and fill it with data's contents
    ca_data *padded = malloc(sizeof(ca_data));
    padded->width = ca->width;
    padded->width += 2;
    padded->height = 1;
    padded->cadata = malloc(sizeof(unsigned char) * padded->width * padded->height);
    padded->qstate = ca->qstate;

    for (int i = 0; i < ca->width; i++)
    {
        padded->cadata[i + 1][0] = ca->cadata[i][0];
    }

    //send to to set1dcaCell
    for (int x = 0; x < ca->width; x++)
    {
        set1DCACell(ca, x, rule(padded, x + 1));
    }
}

void step2DCA(struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int, int))
{
    ca_data *padded = malloc(sizeof(ca_data));
    padded->width = ca->width;
    padded->height = ca->height;
    padded->width += 2;
    padded->height += 2;
    padded->cadata = malloc(sizeof(unsigned char) * padded->width * padded->height);
    padded->qstate = ca->qstate;

    for (int y = 0; y < ca->height; y++)
    {
        for (int x = 0; x < ca->width; x++)
        {
            set2DCACell(ca, x, y, rule(padded, x + 1, y + 1));
        }
    }
}
