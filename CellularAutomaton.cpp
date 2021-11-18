#include "CellularAutomaton.h"
#include <iostream>
using namespace std;
CellularAutomaton::CellularAutomaton(string path, int qstate) {}
CellularAutomaton::CellularAutomaton(CellularAutomaton &copy) {}
CellularAutomaton::~CellularAutomaton() {}
void CellularAutomaton::operator=(CellularAutomaton &copy) {}
int CellularAutomaton::step(unsigned char (*rule)(struct ca_data *, int, int)) {}
void CellularAutomaton::thing(CellularAutomaton &ref) {}