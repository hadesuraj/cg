#include <graphics.h>
#include <conio.h>

void scanlineFill(int x[], int y[], int n) {
    int i, j, temp;
    int le[500], re[500];

    for (i = 0; i < 500; i++) {
        le[i] = 500;
        re[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int x1 = x[i], y1 = y[i];
        int x2 = x[(i + 1) % n], y2 = y[(i + 1) % n];

        if (y2 < y1) {
            temp = x1; x1 = x2; x2 = temp;
            temp = y1; y1 = y2; y2 = temp;
        }

        float m = (x2 - x1) / (float)(y2 - y1);

        float x_int = x1;
        for (int j = y1; j < y2; j++) {
            if (x_int < le[j]) le[j] = (int)x_int;
            if (x_int > re[j]) re[j] = (int)x_int;
            x_int += m;
        }
    }

    for (j = 0; j < 500; j++) {
        if (le[j] <= re[j]) {
            for (int x = le[j]; x <= re[j]; x++) {
                putpixel(x, j, GREEN);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x[] = {150, 250, 200};
    int y[] = {100, 100, 200};
    int n = 3;

    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    scanlineFill(x, y, n);

    getch();
    closegraph();
    return 0;
}

