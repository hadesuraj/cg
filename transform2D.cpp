#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>

#define PI 3.1416

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    float x, y, tx, ty, sx, sy, angle, shx, shy;
    int choice;

    cout << "Enter a point (x y): ";
    cin >> x >> y;

    cout << "Choose Transformation:\n1. Translation\n2. Scaling\n3. Rotation\n4. Shearing\nEnter choice: ";
    cin >> choice;

    putpixel((int)x, (int)y, WHITE);

    switch (choice) {
        case 1:
            cout << "Enter tx and ty: ";
            cin >> tx >> ty;
            x = x + tx;
            y = y + ty;
            break;
        case 2:
            cout << "Enter sx and sy: ";
            cin >> sx >> sy;
            x = x * sx;
            y = y * sy;
            break;
        case 3:
            cout << "Enter angle in degrees: ";
            cin >> angle;
            angle = angle * PI / 180;
            {
                float tempX = x * cos(angle) - y * sin(angle);
                float tempY = x * sin(angle) + y * cos(angle);
                x = tempX;
                y = tempY;
            }
            break;
        case 4:
            cout << "Enter shx and shy: ";
            cin >> shx >> shy;
            {
                float tempX = x + shx * y;
                float tempY = y + shy * x;
                x = tempX;
                y = tempY;
            }
            break;
        default:
            cout << "Invalid choice";
            closegraph();
            return;
    }

    putpixel((int)x, (int)y, GREEN);
    getch();
    closegraph();
}
