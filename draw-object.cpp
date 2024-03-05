#include <graphics.h>
#include <iostream>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int choice;
    cout << "Choose an object to draw:\n";
    cout << "1. Line\n";
    cout << "2. Rectangle\n";
    cout << "3. Arc\n";
    cout << "4. Circle\n";
    cout << "5. Ellipse\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int x1, y1, x2, y2;
        cout << "Enter coordinates of the line (x1 y1 x2 y2): ";
        cin >> x1 >> y1 >> x2 >> y2;
        line(x1, y1, x2, y2);
        break;
    }
    case 2:
    {
        int left, top, right, bottom;
        cout << "Enter coordinates of the rectangle (left top right bottom): ";
        cin >> left >> top >> right >> bottom;
        rectangle(left, top, right, bottom);
        break;
    }
    case 3:
    {
        int x, y, start_angle, end_angle, radius;
        cout << "Enter coordinates and radius of the arc (x y start_angle end_angle radius): ";
        cin >> x >> y >> start_angle >> end_angle >> radius;
        arc(x, y, start_angle, end_angle, radius);
        break;
    }
    case 4:
    {
        int x, y, radius;
        cout << "Enter coordinates and radius of the circle (x y radius): ";
        cin >> x >> y >> radius;
        circle(x, y, radius);
        break;
    }
    case 5:
    {
        int x, y, start_angle, end_angle, x_radius, y_radius;
        cout << "Enter coordinates, start_angle, end_angle, and x and y radius of the ellipse (x y start_angle end_angle x_radius y_radius): ";
        cin >> x >> y >> start_angle >> end_angle >> x_radius >> y_radius;
        ellipse(x, y, start_angle, end_angle, x_radius, y_radius);
        break;
    }
    default:
        cout << "Invalid choice!";
        break;
    }

    getch();
    closegraph();
    return 0;
}
