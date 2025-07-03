#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void midpointLine(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;

    int d = dy - (dx / 2);
    int x = x0, y = y0;

    while (x <= x1) {
        putpixel(x, y, WHITE);
        x++;
        if (d < 0)
            d += dy;
        else {
            d += (dy - dx);
            y++;
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
    midpointLine(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}

