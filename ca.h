#ifndef CA_H_
#define CA_H_

typedef struct ca_data
{
    unsigned char **cadata;
    unsigned char dimension;
    unsigned char wrap;
    int width;
    int height;
    unsigned char qstate;
} ca_data;

void display1DCA(struct ca_data *ca);

int set1DCACell(struct ca_data *ca, unsigned int x, unsigned char state);

int set2DCACell(struct ca_data *ca, unsigned int x, unsigned int y, unsigned char state);

void initCA(struct ca_data *ca, int state);

struct ca_data *create1DCA(int w, unsigned char qstate);

struct ca_data *create2DCA(int w, int h, unsigned char qstate);

void step1DCA(struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int), int x);

void step2DCA(struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int x, int y));

#endif