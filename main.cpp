#include "GraphicsClient.h"
#include <cstddef>
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv)
{
    GraphicsClient gc("127.0.0.1", 7777);
    gc.connection();
    gc.setBackgroundColour(162, 21, 21);
    gc.clear();
    gc.repaint();
    sleep(1);
    gc.setDrawingColour(100, 255, 255);
    gc.drawString(200, 200, "WHAT");
    gc.drawString(50, 50, "toast");
    gc.repaint();
    while (1)
    {
        char check = getchar();
        if (check == 'c')
        {
            printf("clear\n");
            gc.setBackgroundColour(rand() % 255, rand() % 255, rand() % 255);
            gc.clear();
            gc.repaint();
        }
        else if (check == 'r')
        {
            printf("repaint\n");
            gc.repaint();
        }
        else if (check == 'p')
        {
            printf("stars\n");
            for (int i = 0; i < 50; i++)
            {
                gc.setPixel(rand() % 200, rand() % 200, 255, 255, 0);
            }
            gc.repaint();
        }
        else if (check == 'o')
        {
            gc.fillRectangle(100, 100, 200, 200);
            gc.drawRectangle(15, 15, 10, 10);
            gc.clearRectangle(200, 200, 10, 10);
            gc.repaint();
        }
        else if (check == 'u')
        {
            gc.setDrawingColour(rand() % 255, rand() % 255, rand() % 255);
            gc.drawOval(50, 50, 15, 30);
            // gc.fillOval(50, 50, 15, 30);
            gc.repaint();
        }
        else if (check == 'i')
        {
            gc.drawline(0, 0, 200, 200);
            gc.repaint();
        }
        else if (check == 'x')
            break;
    }

    gc.closeConnection();
}