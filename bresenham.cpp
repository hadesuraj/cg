#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x1, y1, x2, y2;
    cout << "Enter start point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter end point (x2 y2): ";
    cin >> x2 >> y2;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1, y = y1;
    int p;
    int incx = (x2 > x1) ? 1 : -1;
    int incy = (y2 > y1) ? 1 : -1;

    if (dx > dy) {
        p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            putpixel(x, y, WHITE);
            x += incx;
            if (p < 0)
                p += 2 * dy;
            else {
                y += incy;
                p += 2 * (dy - dx);
            }
            delay(50);
        }
    } else {
        p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) {
            putpixel(x, y, WHITE);
            y += incy;
            if (p < 0)
                p += 2 * dx;
            else {
                x += incx;
                p += 2 * (dx - dy);
            }
            delay(50);
        }
    }

    getch();
    closegraph();
}
