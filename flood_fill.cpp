#include <graphics.h>
#include <conio.h>

void floodFill(int x, int y, int fillColor, int boundaryColor) {
    int current = getpixel(x, y);
    if (current != boundaryColor && current != fillColor) {
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, boundaryColor);
        floodFill(x - 1, y, fillColor, boundaryColor);
        floodFill(x, y + 1, fillColor, boundaryColor);
        floodFill(x, y - 1, fillColor, boundaryColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Define polygon
    setcolor(WHITE);
    line(100, 100, 200, 100);
    line(200, 100, 200, 200);
    line(200, 200, 100, 200);
    line(100, 200, 100, 100);

    // Fill the polygon
    floodFill(150, 150, GREEN, WHITE);

    getch();
    closegraph();
    return 0;
}

