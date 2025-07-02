#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <iostream.h>

#define ROUND(a) ((int)(a + 0.5))

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xa, ya, xb, yb;
    cout << "Enter start point (x1 y1): ";
    cin >> xa >> ya;
    cout << "Enter end point (x2 y2): ";
    cin >> xb >> yb;

    int dx = xb - xa;
    int dy = yb - ya;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xIncr = dx / (float)steps;
    float yIncr = dy / (float)steps;

    float x = xa, y = ya;
    putpixel(ROUND(x), ROUND(y), WHITE);

    for (int i = 0; i < steps; i++) {
        x += xIncr;
        y += yIncr;
        putpixel(ROUND(x), ROUND(y), WHITE);
        delay(50);
    }

    getch();
    closegraph();
}
