#include "CellularAutomaton.h"
#include <cstddef>
#include <iostream>
#include <unistd.h>
#include "button.h"
using namespace std;

int running = 0;

unsigned char CGOL(CellularAutomaton ca, int x, int y)
{
    int nextX = (x + 1 + ca.getW()) % ca.getW();
    int lastX = (x - 1 + ca.getW()) % ca.getW();
    int nextY = (y + 1 + ca.getH()) % ca.getH();
    int lastY = (y - 1 + ca.getH()) % ca.getH();
    int souls = 0;
    // printf("%d, %d, %d, %d\n", nextX, lastX, nextY, lastY);
    if (ca.getElement(lastY, lastX) == 1)
        souls++;
    if (ca.getElement(lastY, x) == 1)
        souls++;
    if (ca.getElement(lastY, nextX) == 1)
        souls++;
    if (ca.getElement(y, lastX) == 1)
        souls++;
    if (ca.getElement(y, nextX) == 1)
        souls++;
    if (ca.getElement(nextY, lastX) == 1)
        souls++;
    if (ca.getElement(nextY, x) == 1)
        souls++;
    if (ca.getElement(nextY, nextX) == 1)
        souls++;
    // printf("%d\n", ca.getElement(nextY,nextX]);
    if (ca.getElement(y, x) == 1 && souls < 2)
    {
        // printf("0\n");
        return 0;
    }
    else if (ca.getElement(y, x) == 1 && souls > 3)
    {
        // printf("2\n");
        return 0;
    }
    else if (ca.getElement(y, x) == 0 && souls == 3)
    {
        // printf("3\n");
        return 1;
    }
    else
    {
        // printf("4\n");
        return ca.getElement(y, x);
    }
}

int makeGUI(GraphicsClient &gc)
{
    gc.clear();
    gc.setBackgroundcolor(255, 255, 255);
    gc.setDrawingcolor(0, 0, 0);
    gc.clear();
    gc.repaint();
    gc.drawRectangle(0, 0, 799, 599);
    gc.drawRectangle(0, 0, 600, 599);

    gc.drawRectangle(650, 50, 75, 50);
    gc.drawString(675, 75, "STEP"); // option 0

    gc.drawRectangle(650, 100, 75, 50);
    gc.drawString(675, 125, "RUN"); // option 1

    gc.drawRectangle(650, 150, 75, 50);
    gc.drawString(665, 175, "PAUSE"); // option 2

    gc.drawRectangle(650, 200, 75, 50);
    gc.drawString(665, 225, "RESET"); // option 3

    gc.drawRectangle(650, 250, 75, 50);
    gc.drawString(665, 275, "RANDOM"); // option 4

    gc.drawRectangle(650, 300, 75, 50);
    gc.drawString(675, 325, "LOAD"); // option 5

    gc.drawRectangle(650, 350, 75, 50);
    gc.drawString(665, 375, "CLEAR"); // option 6

    gc.drawRectangle(650, 400, 75, 50);
    gc.drawString(675, 425, "QUIT"); // option 7

    gc.drawString(650, 500, "SELECT SIZE");
    gc.drawRectangle(625, 525, 50, 50);
    gc.drawString(650, 550, "1"); // option 8

    gc.drawRectangle(675, 525, 50, 50);
    gc.drawString(700, 550, "2"); // option 9

    gc.drawRectangle(725, 525, 50, 50);
    gc.drawString(750, 550, "3"); // option 10

    gc.repaint();
    return 1;
}

int main(int argc, char **argv)
{
    GraphicsClient gc("127.0.0.1", 7777);
    gc.connection();
    makeGUI(gc);
    int option = -1;
    timespec sleep = {100};
    CellularAutomaton *ca;
    button options[11] = {
        button(650, 725, 50, 100),   // step
        button(650, 725, 100, 150),  // run
        button(650, 725, 150, 200),  // pause
        button(650, 725, 200, 250),  // reset
        button(650, 725, 250, 300),  // random
        button(650, 725, 300, 350),  // load
        button(650, 725, 350, 400),  // clear
        button(650, 725, 400, 450),  // quit
        button(625, 675, 525, 575),  // 1
        button(675, 725, 525, 575),  // 2
        button(725, 775, 525, 575)}; // 3

loop:
    option = gc.whichButton(options);
    switch (option)
    {
    case 0: // step
        ca->step(CGOL);
        ca->graphicalLink(gc);
        goto norm;
    case 1: // run
        running = 1;
        goto norm;
    case 2: // pause
        running = 0;
        goto norm;
    case 3: // reset
        goto norm;
    case 4: // random
        for (int y = 0; y < ca->getH(); y++)
            for (int x = 0; x < ca->getW(); x++)
                ca->setCell(x, y, rand() % 2);
        goto norm;
    case 5: // load
        ca = new CellularAutomaton(gc.load(), 0);
        goto norm;
    case 6: // clear
        for (int y = 0; y < ca->getH(); y++)
            for (int x = 0; x < ca->getW(); x++)
                ca->setCell(x, y, 0);
        goto norm;
    case 7: // quit
        exit(1);
    case 8: // set size 1
        ca->setH(600);
        ca->setW(600);
        break;
    case 9: // set size 2
        ca->setH(150);
        ca->setW(150);
        break;
    case 10: // set size 3
        ca->setH(40);
        ca->setW(40);
        break;
    default:
    norm:
        if (running)
        {
            ca->step(CGOL);
            ca->graphicalLink(gc);
            nanosleep(&sleep, NULL);
        }
        break;
    }

    goto loop;

    gc.closeConnection();
}