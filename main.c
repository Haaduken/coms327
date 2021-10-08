#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca.h"

unsigned char rule110(struct ca_data *data, int index){

    if (data->arr[index-1] == 1 && data->arr[index] == 1 && data->arr[index+1] == 1)
        return 0;
    if (data->arr[index-1] == 1 && data->arr[index] == 1 && data->arr[index+1] == 0)
        return 1;
    if (data->arr[index-1] == 1 && data->arr[index] == 0 && data->arr[index+1] == 1)
        return 1;
    if (data->arr[index-1] == 1 && data->arr[index] == 0 && data->arr[index+1] == 0)
        return 0;
    if (data->arr[index-1] == 0 && data->arr[index] == 1 && data->arr[index+1] == 1)
        return 1;
    if (data->arr[index-1] == 0 && data->arr[index] == 1 && data->arr[index+1] == 0)
        return 1;
    if (data->arr[index-1] == 0 && data->arr[index] == 0 && data->arr[index+1] == 1)
        return 1;
    if (data->arr[index-1] == 0 && data->arr[index] == 0 && data->arr[index+1] == 0)
        return 0;
    return data->arr[index];
}

int main(int argc, char **argv){
    if(argc < 5){
        printf("Not enough args, you had: %d\n", argc);
        return -1;
    }
    int numCells = 0;
    int numStates = 0;
    int wrap = -1;
    int initialState = 0;
    int numSteps = 0;

    if(atoi(argv[1]) < 10 || atoi(argv[1]) > 100){
        printf("Number of cells must be between 10 and 100, you had: %s\n", argv[1]);
        return -1;
    }
    numCells = atoi(argv[1]);

    if(atoi(argv[2]) < 0){
        printf("Number of states must be 0 or greater, you had: %s\n", argv[2]);
        return -1;
    }
    numStates = atoi(argv[2]);

    if(strcmp(argv[3], "wrap") == 0 && (strcmp(argv[3],"nowrap") == 0)){
        printf("Invalid flag to determine if wrapping, you had: %s\n", argv[3]);
        return -1;
    }
    if(!strcmp(argv[3],"wrap")) wrap = 1;
    else wrap = 0;
    
    if(atoi(argv[4]) < -1 || atoi(argv[4]) > numStates-1){
        printf("Initial State value is invalid, it must be between -1 and %d, you had: %s\n", numStates-1, argv[4]);
        return -1;
    }
    initialState = atoi(argv[4]);

    if(atoi(argv[5]) < 0){
        printf("Number of steps must be greater than 0, you had, %s\n", argv[5]);
        return -1;
    }
    numSteps = atoi(argv[5]);
    // printf("%d %d %d %d %d\n",numCells, numStates, wrap, initialState, numSteps);
    ca_data *arr = create1DCA(numCells, initialState);

    if(initialState == -1){
        for(int i = 0; i < numCells; i++){
            set1DCACell(arr, i, rand() % (numStates));
        }
        arr->qstate = 0;
    }

    display1DCA(arr);

    for(int i = 0; i < numSteps; i++){
        stepCA(arr, rule110, wrap);
        display1DCA(arr);
    }
}