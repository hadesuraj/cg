#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

void bresenham_lda(int x0, int y0, int x1, int y1){
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        putpixel(x0, y0, WHITE);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

int main(void) {
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
    return 0;
}
