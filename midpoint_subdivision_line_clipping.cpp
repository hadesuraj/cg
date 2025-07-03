#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int xmin = 100, ymin = 100, xmax = 300, ymax = 250;

void drawWindow() {
    rectangle(xmin, ymin, xmax, ymax);
}

// Check if point is inside the clipping window
int isInside(int x, int y) {
    return (x >= xmin && x <= xmax && y >= ymin && y <= ymax);
}

// Check if the line is completely outside
int isCompletelyOutside(int x1, int y1, int x2, int y2) {
    if ((x1 < xmin && x2 < xmin) || (x1 > xmax && x2 > xmax) ||
        (y1 < ymin && y2 < ymin) || (y1 > ymax && y2 > ymax))
        return 1;
    return 0;
}

// Recursive Midpoint Subdivision
void midpointClip(int x1, int y1, int x2, int y2) {
    if (isInside(x1, y1) && isInside(x2, y2)) {
        // Fully inside: accept
        setcolor(GREEN);
        line(x1, y1, x2, y2);
        return;
    }

    if (isCompletelyOutside(x1, y1, x2, y2)) {
        // Fully outside: reject
        return;
    }

    // Partially inside: subdivide
    int mx = (x1 + x2) / 2;
    int my = (y1 + y2) / 2;

    if (abs(x2 - x1) < 1 && abs(y2 - y1) < 1)
        return; // Too small to subdivide further

    midpointClip(x1, y1, mx, my);
    midpointClip(mx, my, x2, y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    setcolor(WHITE);
    drawWindow();

    // Original line
    int x1 = 50, y1 = 120, x2 = 350, y2 = 200;

    setcolor(RED);
    line(x1, y1, x2, y2); // Draw original line

    // Perform Midpoint Subdivision Clipping
    midpointClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

