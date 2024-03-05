#include<iostream>
#include<graphics.h>
using namespace std;

void translatePoint(int P[], int T[])
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm, NULL);
    
    cout << "Original Coordinate: (" << P[0] << "," << P[1] << ")";
    putpixel(P[0], P[1], GREEN);
    
    P[0] = P[0] + T[0];
    P[1] = P[1] + T[1];
    
    cout << "\nTranslated Coordinates: (" << P[0] << "," << P[1] << ")";
    putpixel(P[0], P[1], YELLOW);
    
    getch();
    closegraph();
}

int main()
{
    int P[2], T[2];
    
    cout << "Enter the original point coordinates (x y): ";
    cin >> P[0] >> P[1];
    
    cout << "Enter the translation vector (Tx Ty): ";
    cin >> T[0] >> T[1];
    
    translatePoint(P, T);
    
    return 0;
}
