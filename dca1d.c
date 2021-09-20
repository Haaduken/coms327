#include <stdio.h>

void init1DCA(int numCells, unsigned char *arr){
    for(int i = 0; i < numCells; i++){
        arr[i] = 0;
    }
}

void set1DCACell(unsigned char *arr, int index, unsigned char setVal){
    if(index < 0) return;
    arr[index] = setVal;
}

void display1DCA(unsigned char *arr, int numCells){
    for(int i = 0; i < numCells; i++){
        printf("%c ", arr[i]);
    }
    printf("\n");
}