#include <iostream>
using namespace std;

class GraphicsClient
{
public:
    GraphicsClient(string _addr, int _port);

    GraphicsClient(GraphicsClient &copy);

    ~GraphicsClient();

    void operator=(string newAddr);

    int connection();

    void setBackgroundColour(int r, int g, int b);

    void setDrawingColour(int r, int g, int b);

    void clear();

    void setPixel(int x, int y, int r, int g, int b);

    void drawRectangle(int x1, int y1, int x2, int y2);

    void fillRectangle(int x1, int y1, int x2, int y2);

    void clearRectangle(int x1, int y1, int x2, int y2);

    void drawOval(int x1, int y1, int x2, int y2);

    void fillOval(int x1, int y1, int x2, int y2);

    void drawline(int x1, int y1, int x2, int y2);

    void drawString(int x1, int y1, int x2, int y2);

    void repaint();

private:
    int port;
    string addr;
    int bgR, bgG, bgB, bg;
    int dwR, dwG, dwB;

    char *toCharArr(string in);
};