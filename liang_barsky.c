#include <graphics.h>
#include <conio.h>
#include <stdio.h>

// Clipping window boundaries
float xmin = 100, ymin = 100, xmax = 300, ymax = 200;

void drawWindow() {
    rectangle(xmin, ymin, xmax, ymax);
}

// Liang-Barsky line clipping function
void liangBarsky(float x0, float y0, float x1, float y1) {
    float dx = x1 - x0;
    float dy = y1 - y0;

    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x0 - xmin, xmax - x0, y0 - ymin, ymax - y0};

    float u1 = 0.0, u2 = 1.0;
    int i;
    for (i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) return;  // Line is parallel and outside the boundary
        } else {
            float u = q[i] / p[i];
            if (p[i] < 0) {
                if (u > u1) u1 = u;
            } else {
                if (u < u2) u2 = u;
            }
        }
    }

    if (u1 > u2) return; // Line is completely outside

    float nx0 = x0 + u1 * dx;
    float ny0 = y0 + u1 * dy;
    float nx1 = x0 + u2 * dx;
    float ny1 = y0 + u2 * dy;

    // Draw the clipped line
    line(nx0, ny0, nx1, ny1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw original window
    drawWindow();

    // Original line
    float x0 = 50, y0 = 150, x1 = 350, y1 = 150;
    setcolor(RED);
    line(x0, y0, x1, y1); // Unclipped line

    getch();
    cleardevice();

    // Draw window again and clipped line
    drawWindow();
    setcolor(GREEN);
    liangBarsky(x0, y0, x1, y1);

    getch();
    closegraph();
    return 0;
}
