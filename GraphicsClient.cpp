#include "GraphicsClient.h"
GraphicsClient::GraphicsClient(string _addr, int _port)
{
}

GraphicsClient::GraphicsClient(GraphicsClient &copy)
{
}

GraphicsClient::~GraphicsClient()
{
}

GraphicsClient GraphicsClient::operator=(string newAddr)
{
}

void GraphicsClient::setBackgroundColour(int r, int g, int b)
{
    bgR = r;
    bgG = g;
    bgB = b;
}

void GraphicsClient::setDrawingColour(int r, int g, int b)
{
    dwR = r;
    dwG = g;
    dwB = b;
}

void GraphicsClient::clear()
{
}

void GraphicsClient::setPixel(int x, int y, int r, int g, int b)
{
}

void GraphicsClient::drawRectangle(int x1, int y1, int x2, int y2)
{
}

void GraphicsClient::fillRectangle(int x1, int y1, int x2, int y2)
{
}

void GraphicsClient::clearRectangle(int x1, int y1, int x2, int y2)
{
}

void GraphicsClient::drawOval(int x1, int y1, int x2, int y2) {}

void GraphicsClient::fillOval(int x1, int y1, int x2, int y2) {}

void GraphicsClient::drawline(int x1, int y1, int x2, int y2) {}

void GraphicsClient::drawString(int x1, int y1, int x2, int y2) {}

void GraphicsClient::repaint() {}