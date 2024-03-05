//  File name: drawobj.cpp
#include <stdio.h>
#include <math.h>
#include<graphics.h>
#include<iostream>
#include<graphics.h>
#include<iostream>
#define PI 3.14
using namespace std;
struct Point 
{
    double x;
    double y;
};
void drawObject(struct Point point[],int s)
{
    for(int i=0;i<s-1;i++)
    {
        line(point[i].x,point[i].y,point[i+1].x,point[i+1].y);
    }
    line(point[s-1].x,point[s-1].y,point[0].x,point[0].y);
}
void print(struct Point point[],int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<"\npoint"<<i<<"\t\tx="<<point[i].x<<"\t\ty="<<point[i].y;
    }
}
