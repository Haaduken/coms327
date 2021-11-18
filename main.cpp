#include "GraphicsClient.h"
#include <cstddef>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    GraphicsClient gc("127.0.0.1", 7777);
    gc.connection();
    gc.setBackgroundColour(162, 162, 162);
    gc.clear();
    gc.setDrawingColour(0, 0, 0);
    gc.drawString(200, 200, "WHAT");
    gc.fillRectangle(0, 0, 1, 1);
    gc.drawline(0, 0, 45, 100);
    // while (1)
    // {
    //     char check = getchar();
    //     if (check == '\n')
    //     {
    //         gc.setBackgroundColour(rand() % 256, rand() % 256, rand() % 256);
    //         gc.clear();
    //         gc.fillRectangle(0, 0, 1, 1);
    //         gc.drawline(0, 0, 45, 100);
    //         gc.repaint();
    //     }
    //     else if (check != '\n')
    //         break;
    // }

    gc.closeConnection();
}