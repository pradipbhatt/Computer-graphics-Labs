#include<iostream>
#include<graphics.h>
using namespace std;

void translatePoint(int P[], int T[])
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "Original Coordinates: (" << P[0] << "," << P[1] << "),(" << P[2] << "," << P[3] << ")";
    line(P[0], P[1], P[2], P[3]);

    P[0] = P[0] + T[0];
    P[1] = P[1] + T[1];
    P[2] = P[2] + T[0];
    P[3] = P[3] + T[1];

    cout << "\nTranslated Coordinates: (" << P[0] << "," << P[1] << "),(" << P[2] << "," << P[3] << ")";
    setcolor(YELLOW);
    line(P[0], P[1], P[2], P[3]);

    getch();
    closegraph();
}

int main()
{
    int P[4], T[2];
    
    cout << "Enter x1, y1, x2, and y2: ";
    for(int i = 0; i <= 3; i++)
    {
        cin >> P[i];
    }

    cout << "Enter tx and ty: ";
    for(int i = 0; i <= 1; i++)
    {
        cin >> T[i];
    }

    translatePoint(P, T);

    return 0;
}
