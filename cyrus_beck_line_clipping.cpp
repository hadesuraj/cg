#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define MAX 10

typedef struct {
    int x, y;
} Point;

Point subtract(Point a, Point b) {
    Point r = {a.x - b.x, a.y - b.y};
    return r;
}

int dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

// Calculate outward normal of edge Pi to Pi+1
Point normal(Point p1, Point p2) {
    Point edge = subtract(p2, p1);
    Point n = { -edge.y, edge.x }; // Outward normal
    return n;
}

// Cyrus-Beck Algorithm
void cyrusBeck(Point p0, Point p1, Point poly[], int n) {
    Point D = subtract(p1, p0);
    float tE = 0.0, tL = 1.0;

    for (int i = 0; i < n; i++) {
        Point pi = poly[i];
        Point pi1 = poly[(i + 1) % n];
        Point N = normal(pi, pi1);
        Point W = subtract(p0, pi);

        int DdotN = dot(D, N);
        int WdotN = dot(W, N);

        if (DdotN == 0) {
            if (WdotN < 0) return; // Line is outside and parallel
            else continue;         // Line is inside or on edge
        }

        float t = -(float)WdotN / DdotN;

        if (DdotN < 0) {
            if (t > tE) tE = t;  // Potentially entering
        } else {
            if (t < tL) tL = t;  // Potentially leaving
        }

        if (tE > tL) return; // Fully outside
    }

    // Clipped line
    Point newP0 = {p0.x + D.x * tE, p0.y + D.y * tE};
    Point newP1 = {p0.x + D.x * tL, p0.y + D.y * tL};

    setcolor(GREEN);
    line(newP0.x, newP0.y, newP1.x, newP1.y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Define convex polygon (clipping window)
    Point poly[] = {{150, 100}, {300, 120}, {280, 220}, {120, 200}};
    int n = 4;

    // Draw polygon
    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        line(poly[i].x, poly[i].y, poly[(i + 1) % n].x, poly[(i + 1) % n].y);
    }

    // Original line (possibly outside)
    Point p0 = {100, 150}, p1 = {350, 180};
    setcolor(RED);
    line(p0.x, p0.y, p1.x, p1.y); // Original

    // Clipped line
    cyrusBeck(p0, p1, poly, n);

    getch();
    closegraph();
    return 0;
}

