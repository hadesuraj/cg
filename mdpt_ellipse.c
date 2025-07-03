#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

void plotEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void midpointEllipse(int rx, int ry, int xc, int yc) {
    int x = 0, y = ry;
    
    // Decision parameters
    float rx2 = rx * rx;
    float ry2 = ry * ry;

    float dx = 2 * ry2 * x;
    float dy = 2 * rx2 * y;

    // Region 1
    float p1 = ry2 - (rx2 * ry) + (0.25 * rx2);
    while (dx < dy) {
        plotEllipsePoints(xc, yc, x, y);
        x++;
        dx = 2 * ry2 * x;
        if (p1 < 0) {
            p1 += ry2 + dx;
        } else {
            y--;
            dy = 2 * rx2 * y;
            p1 += ry2 + dx - dy;
        }
    }

    // Region 2
    float p2 = ry2 * (x + 0.5) * (x + 0.5) + 
               rx2 * (y - 1) * (y - 1) - 
               rx2 * ry2;

    while (y >= 0) {
        plotEllipsePoints(xc, yc, x, y);
        y--;
        dy = 2 * rx2 * y;
        if (p2 > 0) {
            p2 += rx2 - dy;
        } else {
            x++;
            dx = 2 * ry2 * x;
            p2 += rx2 - dy + dx;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,  "C:\\Turboc3\\BGI");

    int xc, yc, rx, ry;
    printf("Enter center (xc yc): ");
    scanf("%d %d", &xc ,&yc);
    printf( "Enter radius (rx ry): ");
    scanf("%d %d", &rx, &ry);

    midpointEllipse(rx, ry, xc, yc);

    getch();
    closegraph();
    return 0;
}

