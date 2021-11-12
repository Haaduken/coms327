#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca.h"

/**
 *  @param ca_data struct to grab array from and output
 */
void displayCA(struct ca_data *data)
{
    for (int y = 0; y < data->height; y++)
    {
        for (int x = 0; x < data->width; x++)
            printf("%d ", data->cadata[y][x]);
        printf("\n");
    }
}

/**
 * @param data which struct to read and write to
 * @param x where to write to in data's cadata width
 * @param setVal what to write in data's cadata width
 * @return 0 on fail, 1 on successful writing
 */
int set1DCACell(struct ca_data *data, unsigned int x, unsigned char setVal)
{
    // printf("AH\n");
    if (x > data->width)
        return 0;

    data->cadata[0][x] = setVal;
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
    ca->cadata[y][x] = state;
    return 1;
}

/**
 * @param data which struct to initialize
 */
void initCA(struct ca_data *data, int initVal)
{
    if (data->dimension == 1)
    {
        for (int x = 0; x < data->width; x++)
        {
            set1DCACell(data, x, data->qstate);
        }
    }
    else
    {
        for (int y = 0; y < data->height; y++)
        {
            for (int x = 0; x < data->width; x++)
            {
                set2DCACell(data, x, y, data->qstate);
            }
        }
    }
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
    data->cadata = malloc(sizeof(unsigned char *) * data->height);
    for (int i = 0; i < data->height; i++)
        data->cadata[i] = malloc(sizeof(unsigned char) * data->width);
    printf("create1DCA after Mallocs\n");
    initCA(data, data->qstate);
    return data;
}

/**
 * @param x how many columns in a newly created ca_data should be
 * @param y how many rows in ca_data
 * @param qstate what the starting state of it should be
 */
struct ca_data *create2DCA(int w, int h, unsigned char qstate)
{
    ca_data *data = malloc(sizeof(ca_data));
    data->height = h;
    data->width = w;
    data->qstate = qstate;
    data->cadata = malloc(sizeof(unsigned char *) * data->height);
    for (int i = 0; i < data->height; i++)
        data->cadata[i] = malloc(sizeof(unsigned char) * data->width);
    initCA(data, data->qstate);
    return data;
}

/**
 * @param data which struct to step through
 * @param rule function pointer to throw data into
 */
void step1DCA(struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int))
{
    ca_data *clone = malloc(sizeof(ca_data));
    clone->width = ca->width;
    clone->height = 1;
    clone->qstate = ca->qstate;

    clone->cadata = malloc(sizeof(unsigned char *) * clone->height);
    clone->cadata[0] = malloc(sizeof(unsigned char) * clone->width);

    for (int i = 0; i < ca->width; i++)
    {
        clone->cadata[0][i] = ca->cadata[0][i];
    }

    for (int x = 0; x < ca->width; x++)
    {
        set1DCACell(ca, x, rule(clone, x));
    }

    free(clone->cadata[0]);
    free(clone->cadata);
    free(clone);
}

void step2DCA(struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int, int))
{
    ca_data *clone = malloc(sizeof(ca_data));
    clone->width = ca->width;
    clone->height = ca->height;
    clone->qstate = ca->qstate;

    clone->cadata = malloc(sizeof(unsigned char *) * clone->height);
    for (int i = 0; i < clone->height; i++)
        clone->cadata[i] = malloc(sizeof(unsigned char) * clone->width);

    for (int j = 0; j < ca->height; j++)
        for (int i = 0; i < ca->width; i++)
            clone->cadata[j][i] = ca->cadata[j][i];

    for (int y = 0; y < ca->height; y++)
    {
        for (int x = 0; x < ca->width; x++)
        {
            set2DCACell(ca, x, y, rule(clone, x, y));
        }
    }

    for (int x = 0; x < ca->height; x++)
    {
        free(clone->cadata[x]);
    }
    free(clone->cadata);
    free(clone);
}