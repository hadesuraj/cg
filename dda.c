#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define ROUND(a) ((int)(a + 0.5))

void dda(int x1, int y1, int x2, int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xIncr = dx / (float)steps;
    float yIncr = dy / (float)steps;

    float x = x1, y = y1;
    putpixel(ROUND(x), ROUND(y), WHITE);
    for (; steps > 0; steps--) {
        x += xIncr;
        y += yIncr;
        putpixel(ROUND(x), ROUND(y), WHITE);
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

    dda(x1, y1, x2, y2);

    getch();
    closegraph();
}
