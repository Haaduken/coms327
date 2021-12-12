#include "CellularAutomaton.h"
#include <iostream>
#include <string.h>

using namespace std;
CellularAutomaton::CellularAutomaton(string path, int state)
{
    FILE *f;
    char *_path = new char[path.size()];
    strcpy(_path, path.c_str());
    qstate = state;
    f = fopen(_path, "r");
    if (f == NULL)
    {
        perror("unable to open file!\n");
        exit(1);
    }
    unsigned char *str = new unsigned char[6];
    fscanf(f, "%d %d", &h, &w);

    createCA();

    unsigned int waF;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (fscanf(f, "%u", &waF) != EOF)
            {
                setCell(x, y, waF);
            }
            else
                break;
        }
    }

    delete str;
    fclose(f);
}

CellularAutomaton::CellularAutomaton(CellularAutomaton &copy)
{
    qstate = copy.qstate;
    w = copy.w;
    h = copy.h;
    cellSize = copy.cellSize;
    pixelGap = copy.pixelGap;
    cadata = new unsigned char *[h];
    for (int i = 0; i < h; i++)
    {
        cadata[i] = new unsigned char[w];
    }
    for (int j = 0; j < h; j++)
    {
        for (int i = 0; i < w; i++)
        {
            cadata[j][i] = copy.cadata[j][i];
        }
    }
}
CellularAutomaton::~CellularAutomaton()
{
    for (int j = 0; j < h; j++)
    {
        delete cadata[j];
    }
    delete cadata;
}
void CellularAutomaton::operator=(CellularAutomaton &copy)
{
    qstate = copy.qstate;
    w = copy.w;
    h = copy.h;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            setCell(x, y, copy.cadata[y][x]);
        }
    }
}
int CellularAutomaton::step(unsigned char (*rule)(CellularAutomaton, int, int))
{
    CellularAutomaton clone(*this);

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            setCell(x, y, rule(clone, x, y));
        }
    }
    return 0;
}
void CellularAutomaton::graphicalLink(GraphicsClient &gc)
{
    int borders = 1;
    int mode = max(h, w);
    if (mode < 1)
        exit(-1);
    else if (mode <= 50)
    {
        cellSize = 10;
        pixelGap = 2;
    }
    else if (mode <= 100)
    {
        cellSize = 4;
        pixelGap = 1;
    }
    else if (mode <= 200)
    {
        borders = 0;
        cellSize = 2;
        pixelGap = 1;
    }
    else if (mode <= 600)
    {
        borders = 0;
        cellSize = 1;
        pixelGap = 0;
    }

    int _x = 0, _y = 0;
    // gc.clear();
    gc.clearDrawSpace();
    gc.repaint();
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (cadata[y][x])
            {
                // printf("OI\n");

                gc.fillRectangle(_x, _y, cellSize, cellSize);
            }
            else
            {
                if (borders)
                    gc.drawRectangle(_x, _y, cellSize, cellSize);
            }
            // printf("x: %d, y: %d, pixGap: %d\n", _x, _y, pixelGap);
            // printf("pre-button\n");
            cells[y][x] = button(_x, _x + cellSize, _y, _y + cellSize);
            // printf("post-button\n");
            _x += pixelGap;
            _x += cellSize;
        }
        _y += pixelGap;
        _y += cellSize;
        _x = 0;
    }
    gc.repaint();
}
int CellularAutomaton::getH() { return h; }
int CellularAutomaton::getW() { return w; }
void CellularAutomaton::setW(int b)
{
    w = b;
}
void CellularAutomaton::setH(int b)
{
    h = b;
}
int CellularAutomaton::getElement(int h, int w) { return cadata[h][w]; }
int CellularAutomaton::setCell(unsigned int x, unsigned int y, unsigned char state)
{
    if (x > w || y > w)
        return 0;
    // printf("%d\n", cadata[y][x]);
    cadata[y][x] = state;
    // printf("%d\n", cadata[y][x]);

    return 1;
}
int CellularAutomaton::getCell(unsigned int x, unsigned int y) { return cadata[y][x]; }

void CellularAutomaton::createCA()
{
    cadata = new unsigned char *[h];
    cells.resize(h);
    for (int i = 0; i < h; i++)
    {
        cells[i].resize(w);
        cadata[i] = new unsigned char[w];
    }
}