#include <stdio.h>
#include "dca1d.h"

#define CELL_SIZE 25

int main(int argc, char **argv){
    unsigned char arr[CELL_SIZE];
    for(int i = 0; i < CELL_SIZE; i++){
        set1DCACell(arr, i, i % 2 == 0 ? '2' : '1');
    }

    display1DCA(arr, CELL_SIZE);
}