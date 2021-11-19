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
    int closeConnection();
    void setBackgroundcolor(int r, int g, int b);
    void setDrawingcolor(int r, int g, int b);
    void clear();
    void setPixel(int x, int y, int r, int g, int b);
    void drawRectangle(int x, int y, int w, int h);
    void fillRectangle(int x, int y, int w, int h);
    void clearRectangle(int x, int y, int w, int h);
    void drawOval(int x, int y, int w, int h);
    void fillOval(int x, int y, int w, int h);
    void drawline(int x, int y, int w, int h);
    void drawString(int x, int y, string out);
    void repaint();

private:
    int port;
    string addr;
    char message[100];
    char *toCharArr(string in);
    void zeroSet();
    void shape(int x1, int y, int w, int h);
};