#ifndef CA_H_
#define CA_H_

typedef struct ca_data{
    int cellCount;
    unsigned char *arr;
    int wrapping;
    unsigned char qstate;
} ca_data;

void display1DCA(struct ca_data *data);

int set1DCACell(struct ca_data *data, unsigned int index, unsigned char setVal);

void init1DCA(struct ca_data *data, int initVal);

struct ca_data * create1DCA(int numCells, unsigned char initialVal); 

void stepCA( struct ca_data *data, unsigned char (*function)(struct ca_data *, int), int edgeCase);

#endif