#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca.h"

void display1DCA(struct ca_data *data){
    for(int i = 0; i < data->cellCount; i++){
        printf("%c ", data->arr[i]);
    }
    printf("\n");
}

int set1DCACell(struct ca_data *data, unsigned int index, unsigned char setVal){
    if(index > data->cellCount) return -1;
    data->arr[index] = setVal;
    return 1;
}

void init1DCA(struct ca_data *data, int initVal){
    memset(data->arr, (int)(initVal), sizeof(ca_data));
}

struct ca_data * create1DCA(int numCells, unsigned char initialVal){
    ca_data *a = malloc(sizeof(ca_data));
    a->cellCount = numCells;
    a->arr = malloc(sizeof(unsigned char) * a->cellCount);
    init1DCA(a, numCells);
    for(int i = 0; i < numCells; i++){
        set1DCACell(a, i, initialVal);
    }
    return a;
}

void stepCA( struct ca_data *data, unsigned char (*function)(struct ca_data *, int), int edgeCase){
    
}