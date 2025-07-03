#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.1416

void Transform2D(){
    float x, y, tx, ty, sx, sy, angle, shx, shy;
    int choice;

    printf("Enter a point (x y): ");
    scanf("%f %f", &x, &y);

    printf("Choose Transformation:\n1. Translation\n2. Scaling\n3. Rotation\n4. Shearing\nEnter choice: ");
    scanf("%d", &choice);

    putpixel((int)x, (int)y, WHITE);

    switch (choice) {
        case 1:
            printf( "Enter tx and ty: ");
            scanf("%f %f", &tx, &ty);
            x = x + tx;
            y = y + ty;
            break;
        case 2:
            printf( "Enter sx and sy: ");
            scanf("%f %f", &sx, &sy);
            x = x * sx;
            y = y * sy;
            break;
        case 3:
            printf( "Enter angle in degrees: ");
            scanf("%f", &angle);
            angle = angle * PI / 180;
            {
                float tempX = x * cos(angle) - y * sin(angle);
                float tempY = x * sin(angle) + y * cos(angle);
                x = tempX;
                y = tempY;
            }
            break;
        case 4:
            printf( "Enter shx and shy: ");
            scanf("%f %f", &shx, &shx);
            {
                float tempX = x + shx * y;
                float tempY = y + shy * x;
                x = tempX;
                y = tempY;
            }
            break;
        default:
            printf("Invalid choice");
            closegraph();
            return;
    }

    putpixel((int)x, (int)y, GREEN);

}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    Transform2D();
    getch();
    closegraph();
}
