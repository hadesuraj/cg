#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void plot(int x, int y, int cx, int cy){
    putpixel(cx + x, cy + y, WHITE);
    putpixel(cx + x, cy - y, WHITE);
    putpixel(cx - x, cy + y, WHITE);
    putpixel(cx - x, cy - y, WHITE);
    putpixel(cx + y, cy + x, WHITE);
    putpixel(cx + y, cy - x, WHITE);
    putpixel(cx - y, cy + x, WHITE);
    putpixel(cx - y, cy - x, WHITE);
}

void mdpt_circle(int cx, int cy, int r){
    int x = 0, y = r;
    int p = 1 - r;

    plot(x, y, cx, cy);

    while (x < y) {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        plot(x, y, cx, cy);
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, r;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    printf("Enter center (x1 y1): ");
    scanf("%d %d", &x1 ,&y1);
    printf( "Enter radius (R): ");
    scanf("%d", &r);
    mdpt_circle(x1, y1, r);
    getch();
    closegraph();
    return 0;
}
