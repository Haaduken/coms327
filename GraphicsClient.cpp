#include "GraphicsClient.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

GraphicsClient::GraphicsClient(string _addr, int _port)
{
    if (strcmp(toCharArr(_addr), "localhost") || strcmp(toCharArr(_addr), "lamb.cs.iastate.edu"))
        cout << "Invalid address" << endl;
    if (_port <= 0)
        cout << "Invalid port number" << endl;
    addr = _addr;
    port = _port;
}

GraphicsClient::GraphicsClient(GraphicsClient &copy)
{
    addr = copy.addr;
    port = copy.port;
    connection();
    // setBackgroundColour(copy.bgR, copy.bgG, copy.bgB);
    // setDrawingColour(copy.dwR, copy.dwG, copy.dwB);
}

GraphicsClient::~GraphicsClient()
{
    // delete this;
}

void GraphicsClient::operator=(string newAddr)
{
    //close connection
    addr = newAddr;
    //start new connection
}

int GraphicsClient::connection()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, toCharArr(addr), &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock, "ah", strlen("ah"), 0);
    printf("Hello message sent\n");
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);
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

char *GraphicsClient::toCharArr(string in)
{
    char out[in.size() + 1];
    strcpy(out, in.c_str());
    return out;
}