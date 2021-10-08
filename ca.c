#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca.h"

void display1DCA(struct ca_data *data){
    for(int i = 0; i < data->cellCount; i++){
        printf("%d ", data->arr[i]);
    }
    printf("\n");
}

int set1DCACell(struct ca_data *data, unsigned int index, unsigned char setVal){
    if(index > data->cellCount) return 0;
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
    a->qstate = initialVal;
    init1DCA(a, initialVal);
    for(int i = 0; i < numCells; i++){
        set1DCACell(a, i, initialVal);
    }
    return a;
}

void stepCA( struct ca_data *data, unsigned char (*rule)(struct ca_data *, int), int edgeCase){
    data->wrapping = edgeCase;
    ca_data *padded = malloc(sizeof(ca_data));
    padded->cellCount = data->cellCount;
    padded->cellCount += 2;
    padded->arr = malloc(sizeof(unsigned char) * padded->cellCount);
    padded->qstate = data->qstate;
    
    for(int i = 0; i < data->cellCount; i++){
        padded->arr[i+1] = data->arr[i];
    } 

    if(edgeCase){
        padded->arr[padded->cellCount-1] = data->arr[0];
        padded->arr[0] = data->arr[data->cellCount-1];
    }
    else{
        padded->arr[padded->cellCount-1] = padded->qstate;
        padded->arr[0] = padded->qstate;
    }
    for(int i = 0; i < data->cellCount; i++){
        set1DCACell(data, i, rule(padded, i+1));
    }
    
}