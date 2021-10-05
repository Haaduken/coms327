#include <stdio.h>
// #include "dca1d.h"
#include "ca.h"

#define CELL_SIZE 25

int main(int argc, char **argv){
    // unsigned char arr[CELL_SIZE];
    ca_data *arr = create1DCA(CELL_SIZE, 1);
    for(int i = 0; i < CELL_SIZE; i++){
        set1DCACell(arr, i, i % 2 == 0 ? '2' : '1');
    }

    display1DCA(arr);
}