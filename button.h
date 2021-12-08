#include <iostream>
class button
{

public:
    button(int _x1, int _x2, int _y1, int _y2)
    {
        x1 = _x1;
        x2 = _x2;
        y1 = _y1;
        y2 = _y2;
    }

    int within(int x, int y) { return (x1 <= x && x <= x2 && y1 <= y && y <= y2); }

private:
    int x1, x2, y1, y2;
};