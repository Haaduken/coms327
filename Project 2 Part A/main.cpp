#include "CellularAutomaton.h"
#include <cstddef>
#include <iostream>
#include <unistd.h>
using namespace std;

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

int main(int argc, char **argv)
{
    GraphicsClient gc("127.0.0.1", 7777);
    gc.connection();
    gc.setBackgroundcolor(18, 11, 140);
    gc.setDrawingcolor(171, 10, 80);
    gc.clear();
    gc.repaint();
    CellularAutomaton ca(argv[1], 0);
    ca.graphicalLink(gc);

    while (1)
    {
        char check = getchar();
        if (check == '\n')
        {
            ca.step(CGOL);
            ca.graphicalLink(gc);
        }
        else if (check != '\n')
        {
            gc.closeConnection();
            break;
        }
    }

    // gc.connection();
    // gc.setBackgroundcolor(162, 21, 21);
    // gc.clear();
    // gc.repaint();
    // sleep(1);
    // gc.setDrawingcolor(100, 255, 255);
    // gc.drawString(200, 200, "WHAT");
    // gc.drawString(50, 50, "toast");
    // gc.repaint();
    // while (1)
    // {
    //     char check = getchar();
    //     if (check == 'c')
    //     {
    //         printf("clear\n");
    //         gc.setBackgroundcolor(rand() % 255, rand() % 255, rand() % 255);
    //         gc.clear();
    //         gc.repaint();
    //     }
    //     else if (check == 'r')
    //     {
    //         printf("repaint\n");
    //         gc.repaint();
    //     }
    //     else if (check == 'p')
    //     {
    //         printf("stars\n");
    //         for (int i = 0; i < 50; i++)
    //         {
    //             gc.setPixel(rand() % 200, rand() % 200, 255, 255, 0);
    //         }
    //         gc.repaint();
    //     }
    //     else if (check == 'o')
    //     {
    //         gc.fillRectangle(100, 100, 200, 200);
    //         gc.drawRectangle(15, 15, 10, 10);
    //         gc.clearRectangle(200, 200, 10, 10);
    //         gc.repaint();
    //     }
    //     else if (check == 'u')
    //     {
    //         gc.setDrawingcolor(rand() % 255, rand() % 255, rand() % 255);
    //         gc.drawOval(50, 50, 15, 30);
    //         // gc.fillOval(50, 50, 15, 30);
    //         gc.repaint();
    //     }
    //     else if (check == 'i')
    //     {
    //         gc.drawline(0, 0, 200, 200);
    //         gc.repaint();
    //     }
    //     else if (check == 'x')
    //         break;
    // }

    gc.closeConnection();
}