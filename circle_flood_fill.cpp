#include <graphics.h>
#include <conio.h>

void floodFill(int x, int y, int fillColor, int borderColor) {
    int current = getpixel(x, y);
    if (current != borderColor && current != fillColor) {
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, borderColor);
        floodFill(x - 1, y, fillColor, borderColor);
        floodFill(x, y + 1, fillColor, borderColor);
        floodFill(x, y - 1, fillColor, borderColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x = 250, y = 200, r = 80;

    setcolor(WHITE);
    circle(x, y, r);               // Draw circle border

    floodFill(x, y, GREEN, WHITE); // Fill circle

    getch();
    closegraph();
    return 0;
}

