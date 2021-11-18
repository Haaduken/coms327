#include <iostream>
using namespace std;

class CellularAutomaton
{
public:
    CellularAutomaton(string path, int qstate);
    CellularAutomaton(CellularAutomaton &copy);
    ~CellularAutomaton();
    void operator=(CellularAutomaton &copy);
    int step(unsigned char (*rule)(struct ca_data *, int, int));
    void thing(CellularAutomaton &ref);

private:
    unsigned char **cadata;
    int width;
    int height;
    unsigned char qstate;
};