#include <iostream.h>
#include <stdlib.h>

typedef struct {
    float x, y, z;
} Point3D;

void parallel_project(Point3D p, int *px, int *py) {
    *px = (int)p.x + 40;
    *py = 12 - (int)p.y;
}

void perspective_project(Point3D p, int *px, int *py) {
    float d = 100.0;
    *px = (int)((p.x * d) / (p.z + d)) + 40;
    *py = 12 - (int)((p.y * d) / (p.z + d));
}

void main() {
    int choice, n;
    cout << "===== 3D to 2D Projection Tool =====\n";
    cout << "Enter number of 3D points: ";
    cin >> n;

    Point3D *points = new Point3D[n];

    for (int i = 0; i < n; ++i) {
        cout << "Enter x, y, z for Point " << i << ": ";
        cin >> points[i].x >> points[i].y >> points[i].z;
    }

    cout << "\nChoose Projection Type:\n1. Parallel (Orthographic)\n2. Perspective\nEnter choice (1 or 2): ";
    cin >> choice;

    cout << "\n== Projected Points ==\n";
    for (int i = 0; i < n; ++i) {
        int x, y;
        if (choice == 1)
            parallel_project(points[i], &x, &y);
        else if (choice == 2)
            perspective_project(points[i], &x, &y);
        else {
            cout << "Invalid choice. Exiting.\n";
            delete[] points;
            return;
        }
        cout << "Point " << i << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ") -> Pixel: (" << x << ", " << y << ")\n";
    }

    delete[] points;
}
