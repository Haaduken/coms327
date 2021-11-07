#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca.h"

/**
 *  @param ca_data struct to grab array from and output
 */
void display1DCA(struct ca_data *data){
    for(int i = 0; i < data->cellCount; i++){
        printf("%d ", data->arr[i]);
    }
    printf("\n");
}

/**
 * @param data which struct to read and write to
 * @param index where to write to in data's arr
 * @param setVal what to write in data's arr
 * @return 0 on fail, 1 on successful writing
 */
int set1DCACell(struct ca_data *data, unsigned int index, unsigned char setVal){
    if(index > data->cellCount) return 0;
    data->arr[index] = setVal;
    return 1;
}

int set2DCACell( struct ca_data *ca, unsigned int x, unsigned int y, unsigned char state){

}


/**
 * @param data which struct to initialize
 */
void initCA(struct ca_data *data, int initVal){
    memset(data->arr, (int)(initVal), sizeof(ca_data));
}

/**
 * @param numCells how large the array in a newly created ca_data should be
 * @param initialVal what the starting state of it should be
 */
struct ca_data * create1DCA(int numCells, unsigned char initialVal){
    ca_data *data = malloc(sizeof(ca_data));
    data->cellCount = numCells;
    data->arr = malloc(sizeof(unsigned char) * data->cellCount);
    data->qstate = initialVal;
    init1DCA(data, initialVal);
    for(int i = 0; i < numCells; i++){
        set1DCACell(data, i, initialVal);
    }
    return data;
}

struct ca_data * create2DCA( int w, int h, unsigned char qstate){

}


/**
 * @param data which struct to step through
 * @param rule function pointer to throw data into
 * @param edgeCase flag to determine if the data should wrap or not
 */
void step1DCA( struct ca_data *data, unsigned char (*rule)(struct ca_data *, int), int edgeCase){
    data->wrap = edgeCase;
    //create a padded copy of data (+1 on each side) and fill it with data's contents
    ca_data *padded = malloc(sizeof(ca_data)); 
    padded->cellCount = data->cellCount;
    padded->cellCount += 2;
    padded->arr = malloc(sizeof(unsigned char) * padded->cellCount);
    padded->qstate = data->qstate;
    
    for(int i = 0; i < data->cellCount; i++){
        padded->arr[i+1] = data->arr[i];
    } 

    //if we are wrapping, assign last value to the front padded one, and last value to the first
    if(edgeCase){
        padded->arr[padded->cellCount-1] = data->arr[0];
        padded->arr[0] = data->arr[data->cellCount-1];
    }
    else{
        padded->arr[padded->cellCount-1] = padded->qstate;
        padded->arr[0] = padded->qstate;
    }

    //send to to set1dcaCell
    for(int i = 0; i < data->cellCount; i++){
        set1DCACell(data, i, rule(padded, i+1));
    }
    
}

void step2DCA( struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int x, int y)){

}
