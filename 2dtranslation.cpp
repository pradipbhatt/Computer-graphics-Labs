#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    //  input inital parameters
    int initial_x, initial_y;
    cout << "Enter Initial coordinate of X =\n";
    cin >> initial_x;
    cout << "Enter Initial coordinate of Y=\n";
    cin >> initial_y;

    // dRAW INITIAL LINE
    line(initial_x, initial_y, initial_x + 100, initial_y + 100);

    // Translation
    int translate_x, traslatey;
    cout << "Enter Translation coordinate of X";
    cin >> translate_x;
    cout << "Enter Translation coordinate of Y";
    cin >> traslatey;

    // Initial translate coordinates
    int final_x = initial_x + translate_x;
    int final_y = initial_y + traslatey;
    // Draw the translated line

    setcolor(BLUE);
    line(final_x, final_y, final_x + 100, final_y + 100);

    getch();
    closegraph();
    return 0;
}