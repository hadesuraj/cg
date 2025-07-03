#include <graphics.h>
#include <stdio.h>
#include <conio.h>

float xmin = 100, ymin = 100, xmax = 300, ymax = 250;

void drawWindow() {
    rectangle(xmin, ymin, xmax, ymax);
}

int liangBarsky(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    float u1 = 0.0, u2 = 1.0;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) return 0; // Line is parallel and outside
        } else {
            float r = q[i] / p[i];
            if (p[i] < 0)
                if (r > u1) u1 = r;
            if (p[i] > 0)
                if (r < u2) u2 = r;
        }
    }

    if (u1 > u2) return 0; // Line is outside

    int x_start = x1 + u1 * dx;
    int y_start = y1 + u1 * dy;
    int x_end   = x1 + u2 * dx;
    int y_end   = y1 + u2 * dy;

    setcolor(GREEN);
    line(x_start, y_start, x_end, y_end);

    return 1;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw clipping window
    setcolor(WHITE);
    drawWindow();

    // Original line (can be outside or intersecting)
    int x1 = 50, y1 = 150, x2 = 350, y2 = 200;
    setcolor(RED);
    line(x1, y1, x2, y2); // Draw original line

    // Clipped line in green
    liangBarsky(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

