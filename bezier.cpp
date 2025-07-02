#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>

float bezierPoint(float p0, float p1, float p2, float p3, float t) {
    return pow(1 - t, 3) * p0 +
           3 * t * pow(1 - t, 2) * p1 +
           3 * t * t * (1 - t) * p2 +
           t * t * t * p3;
}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    float x0, y0, x1, y1, x2, y2, x3, y3;
    cout << "Enter 4 control points (P0 to P3):\n";
    cout << "P0 (x0 y0): "; cin >> x0 >> y0;
    cout << "P1 (x1 y1): "; cin >> x1 >> y1;
    cout << "P2 (x2 y2): "; cin >> x2 >> y2;
    cout << "P3 (x3 y3): "; cin >> x3 >> y3;

    for (float t = 0.0; t <= 1.0001; t += 0.01) {
        float x = bezierPoint(x0, x1, x2, x3, t);
        float y = bezierPoint(y0, y1, y2, y3, t);
        putpixel((int)x, (int)y, WHITE);
        delay(10);
    }

    getch();
    closegraph();
}
