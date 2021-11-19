#include "GraphicsClient.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;

int sockfd = socket(AF_INET, SOCK_STREAM, 0);

GraphicsClient::GraphicsClient(string _addr, int _port)
{
    if (strcmp(toCharArr(_addr), "localhost") && strcmp(toCharArr(_addr), "lamb.cs.iastate.edu") && strcmp(toCharArr(_addr), "127.0.0.1"))
    {
        cout << "Invalid address" << endl;
        // exit(-1);
    }
    if (_port <= 0)
    {
        cout << "Invalid port number" << endl;
        exit(-1);
    }
    addr = _addr;
    port = _port;
}

GraphicsClient::GraphicsClient(GraphicsClient &copy)
{
    addr = copy.addr;
    port = copy.port;
    connection();
}

GraphicsClient::~GraphicsClient()
{
    closeConnection();
}

void GraphicsClient::operator=(string newAddr)
{
    closeConnection();
    addr = newAddr;
    connection();
}

int GraphicsClient::connection()
{
    if (sockfd < 0)
    {
        fprintf(stderr, "Error creating socket\n");
        exit(-1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, toCharArr(addr), &serv_addr.sin_addr) <= 0)
    {
        fprintf(stderr, "Invalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "Connection Failed \n");
        return -1;
    }

    // message[0] = 0xFF;
    // message[1] = 0x00;
    // message[2] = 0x00;
    // message[3] = 0x00;
    // message[4] = 0x07;
    // message[5] = 0x02;
    // message[6] = 0x00;
    // message[7] = 0x05;
    // message[8] = 0x0F;
    // message[9] = 0x0F;
    // message[10] = 0x00;
    // message[11] = 0x00;

    // send(sockfd, message, 12, 0);

    // message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send(sockfd, message, 6, 0);

    return 1;
}

int GraphicsClient::closeConnection()
{
    close(sockfd);
    return EXIT_SUCCESS;
}

void GraphicsClient::setBackgroundColour(int r, int g, int b)
{
    zeroSet();
    message[1] = 0x00;     //size pt4
    message[2] = 0x00;     //size pt3
    message[3] = 0x00;     //size pt2
    message[4] = 0x07;     //size pt1
    message[5] = 0x02;     //cmd
    message[6] = r >> 4;   //red upper
    message[7] = r & 0xF;  //red lower
    message[8] = g >> 4;   //green upper
    message[9] = g & 0xF;  //green lower
    message[10] = b >> 4;  //blue upper
    message[11] = b & 0xF; //blue lower
    send(sockfd, message, 12, 0);
}

void GraphicsClient::setDrawingColour(int r, int g, int b)
{
    zeroSet();
    message[1] = 0x00;     //size pt4
    message[2] = 0x00;     //size pt3
    message[3] = 0x00;     //size pt2
    message[4] = 0x07;     //size pt1
    message[5] = 0x06;     //cmd
    message[6] = r >> 4;   //red upper
    message[7] = r & 0xF;  //red lower
    message[8] = g >> 4;   //green upper
    message[9] = g & 0xF;  //green lower
    message[10] = b >> 4;  //blue upper
    message[11] = b & 0xF; //blue lower
    send(sockfd, message, 12, 0);
}

void GraphicsClient::clear()
{
    zeroSet();
    message[1] = 0x00;
    message[2] = 0x00;
    message[3] = 0x00;
    message[4] = 0x01;
    message[5] = 0x01;
    send(sockfd, message, 6, 0);
}

void GraphicsClient::setPixel(int x, int y, int r, int g, int b)
{
    zeroSet();
    message[1] = 0x00; //size pt4
    message[2] = 0x00; //size pt3
    message[3] = 0x00; //size pt2
    message[4] = 0x0F; //size pt1
    message[5] = 0x03; //cmd
    message[6] = x >> 12;
    message[7] = x >> 8;
    message[8] = x >> 4;
    message[9] = x & 0xF;
    message[10] = y >> 12;
    message[11] = y >> 8;
    message[12] = y >> 4;
    message[13] = y & 0xF;
    message[14] = r >> 4;  //red upper
    message[15] = r & 0xF; //red lower
    message[16] = g >> 4;  //green upper
    message[17] = g & 0xF; //green lower
    message[18] = b >> 4;  //blue upper
    message[19] = b & 0xF; //blue lower
    send(sockfd, message, 20, 0);
}

void GraphicsClient::drawRectangle(int x, int y, int w, int h)
{

    zeroSet();
    message[1] = 0x00; //size pt4
    message[2] = 0x00; //size pt3
    message[3] = 0x01; //size pt2
    message[4] = 0x01; //size pt1
    message[5] = 0x07; //cmd
    shape(x, y, w, h);
    send(sockfd, message, 22, 0);
}

void GraphicsClient::fillRectangle(int x, int y, int w, int h)
{
    zeroSet();
    message[1] = 0x00; //size pt4
    message[2] = 0x00; //size pt3
    message[3] = 0x01; //size pt2
    message[4] = 0x01; //size pt1
    message[5] = 0x08; //cmd
    shape(x, y, w, h);
    for (int i = 0; i < 22; i++)
    {
        printf("0x%X\n", message[i]);
    }
    send(sockfd, message, 22, 0);
}

void GraphicsClient::clearRectangle(int x, int y, int w, int h)
{
    zeroSet();
    message[1] = 0x00; //size pt4
    message[2] = 0x00; //size pt3
    message[3] = 0x01; //size pt2
    message[4] = 0x01; //size pt1
    message[5] = 0x09; //cmd
    shape(x, y, w, h);
    send(sockfd, message, 22, 0);
}

void GraphicsClient::drawOval(int x, int y, int w, int h)
{
    zeroSet();
    message[1] = 0x00; //size pt4
    message[2] = 0x00; //size pt3
    message[3] = 0x01; //size pt2
    message[4] = 0x01; //size pt1
    message[5] = 0x0A; //cmd
    shape(x, y, w, h);
    send(sockfd, message, 22, 0);
}

void GraphicsClient::fillOval(int x, int y, int w, int h)
{
    zeroSet();
    message[1] = 0x00; //size pt4
    message[2] = 0x00; //size pt3
    message[3] = 0x01; //size pt2
    message[4] = 0x01; //size pt1
    message[5] = 0x0B; //cmd
    shape(x, y, w, h);
    send(sockfd, message, 22, 0);
}

void GraphicsClient::drawline(int x, int y, int w, int h)
{
    zeroSet();
    message[1] = 0x00; //size pt4
    message[2] = 0x00; //size pt3
    message[3] = 0x01; //size pt2
    message[4] = 0x01; //size pt1
    message[5] = 0x0D; //cmd
    message[6] = x >> 12;
    message[7] = x >> 8;
    message[8] = x >> 4;
    message[9] = x & 0xF;
    message[10] = y >> 12;
    message[11] = y >> 8;
    message[12] = y >> 4;
    message[13] = y & 0xF;
    message[14] = w >> 12;
    message[15] = w >> 8;
    message[16] = w >> 4;
    message[17] = w & 0xF;
    message[18] = h >> 12;
    message[19] = h >> 8;
    message[20] = h >> 4;
    message[21] = h & 0xF;
    printf("%ld\n", send(sockfd, message, 22, 0));
}
void GraphicsClient::drawString(int x, int y, string out)
{
    int size = out.size() * 2 + 9;
    char *arr = toCharArr(out);
    zeroSet();
    message[1] = size >> 12; //size pt4
    message[2] = size >> 8;  //size pt3
    message[3] = size >> 4;  //size pt2
    message[4] = size & 0xF; //size pt1
    message[5] = 0x05;       //cmd
    message[6] = x >> 12;
    message[7] = x >> 8;
    message[8] = x >> 4;
    message[9] = x & 0xF;
    message[10] = y >> 12;
    message[11] = y >> 8;
    message[12] = y >> 4;
    message[13] = y & 0xF;

    for (int i = 0, j = 14; i < out.size(); i++, j += 2)
    {
        message[j] = arr[i] >> 4;
        message[j + 1] = arr[i] & 0xF;
        // printf("%X %X\n", arr[i] >> 4, arr[i] & 0xF);
    }
    // for (int i = 0; i < size; i++)
    // {
    //     printf("0x%X\n", message[i]);
    // }
    // printf("%d", size);
    send(sockfd, message, out.size() * 2 + 14, 0);
}

void GraphicsClient::repaint()
{
    zeroSet();
    message[1] = 0x00; //size pt4
    message[2] = 0x00; //size pt3
    message[3] = 0x00; //size pt2
    message[4] = 0x01; //size pt1
    message[5] = 0x0C; //cmd
    send(sockfd, message, 6, 0);
}

char *GraphicsClient::toCharArr(string in)
{
    char *out = new char[in.size()];
    strcpy(out, in.c_str());
    return out;
}

void GraphicsClient::zeroSet()
{
    for (int i = 0; i < 100; i++)
    {
        message[i] = 0x00;
    }
    message[0] = 0xFF;
}

void GraphicsClient::shape(int x, int y, int w, int h)
{
    message[6] = x >> 12;
    message[7] = x >> 8;
    message[8] = x >> 4;
    message[9] = x & 0xF;
    message[10] = y >> 12;
    message[11] = y >> 8;
    message[12] = y >> 4;
    message[13] = y & 0xF;
    message[14] = w >> 12;
    message[15] = w >> 8;
    message[16] = w >> 4;
    message[17] = w & 0xF;
    message[18] = h >> 12;
    message[19] = h >> 8;
    message[20] = h >> 4;
    message[21] = h & 0xF;
}