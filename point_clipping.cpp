#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define xmin 100
#define ymin 100
#define xmax 300
#define ymax 250

// Function to check if point is inside the window
int isInside(int x, int y) {
    return (x >= xmin && x <= xmax && y >= ymin && y <= ymax);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw clipping rectangle
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Sample points
    int points[][2] = {
        {120, 130},
        {310, 200},
        {250, 260},
        {280, 180},
        {90, 90}
    };

    int n = sizeof(points) / sizeof(points[0]);

    for (int i = 0; i < n; i++) {
        int x = points[i][0];
        int y = points[i][1];

        if (isInside(x, y)) {
            setcolor(GREEN);
            outtextxy(x + 5, y, "✓");
        } else {
            setcolor(RED);
            outtextxy(x + 5, y, "×");
        }

        // Draw the point itself
        putpixel(x, y, YELLOW);
    }

    getch();
    closegraph();
    return 0;
}

