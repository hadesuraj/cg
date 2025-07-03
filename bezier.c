#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

float bezierPoint(float p0, float p1, float p2, float p3, float t) {
    return pow(1 - t, 3) * p0 +
           3 * t * pow(1 - t, 2) * p1 +
           3 * t * t * (1 - t) * p2 +
           t * t * t * p3;
}

void main() {
    int gd = DETECT, gm;
    float x0, y0, x1, y1, x2, y2, x3, y3, t, x, y;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    printf("Enter 4 control points (P0 to P3):\n");
    printf("P0 (x0 y0): "); scanf("%f %f", &x0 ,&y0);
    printf("P1 (x1 y1): "); scanf("%f %f", &x1 ,&y1);
    printf("P2 (x2 y2): "); scanf("%f %f", &x2 ,&y2);
    printf("P3 (x3 y3): "); scanf("%f %f", &x3 ,&y3);

    for (t = 0.0; t <= 1.0001; t += 0.01) {
        x = bezierPoint(x0, x1, x2, x3, t);
        y = bezierPoint(y0, y1, y2, y3, t);
        putpixel((int)x, (int)y, WHITE);
    }

    getch();
    closegraph();
}
