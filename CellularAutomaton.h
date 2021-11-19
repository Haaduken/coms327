#include <iostream>
#include "GraphicsClient.h"

using namespace std;

class CellularAutomaton
{
public:
    CellularAutomaton(string path, int qstate);
    CellularAutomaton(CellularAutomaton &copy);
    ~CellularAutomaton();
    void operator=(CellularAutomaton &copy);
    int step(unsigned char (*rule)(CellularAutomaton, int, int));
    void graphicalLink(GraphicsClient &ref);
    int getW();
    int getH();
    int getElement(int x, int y);

private:
    unsigned char **cadata;
    int w;
    int h;
    unsigned char qstate;
    int pixelGap, cellSize;
    int setCell(unsigned int x, unsigned int y, unsigned char state);
};