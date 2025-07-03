#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

void bresenham_lda(int x1, int y1, int x2, int y2){
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1, y = y1;
    int p, i;
    int incx = (x2 > x1) ? 1 : -1;
    int incy = (y2 > y1) ? 1 : -1;

    if (dx > dy) {
        p = 2 * dy - dx;
        for (i = 0; i <= dx; i++) {
            putpixel(x, y, WHITE);
            x += incx;
            if (p < 0)
                p += 2 * dy;
            else {
                y += incy;
                p += 2 * (dy - dx);
            }
        }
    } else {
        p = 2 * dx - dy;
        for (i = 0; i <= dy; i++) {
            putpixel(x, y, WHITE);
            y += incy;
            if (p < 0)
                p += 2 * dx;
            else {
                x += incx;
                p += 2 * (dx - dy);
            }
        }
    }
}

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("Enter start point (x1 y1): ");
    scanf("%d %d", &x1 ,&y1);
    printf( "Enter end point (x2 y2): ");
    scanf("%d %d", &x2 ,&y2);
    bresenham_lda(x1, y1, x2, y2);
    getch();
    closegraph();
}
