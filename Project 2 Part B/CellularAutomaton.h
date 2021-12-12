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
    void graphicalLink(GraphicsClient &gc);
    int getW();
    void setW(int b);
    int getH();
    void setH(int b);
    int getElement(int x, int y);
    int setCell(unsigned int x, unsigned int y, unsigned char state);
    int getCell(unsigned int x, unsigned int y);
    void createCA();
    vector<vector<button>> cells;

private:
    unsigned char **cadata;
    int w;
    int h;
    unsigned char qstate;
    int pixelGap, cellSize;
};