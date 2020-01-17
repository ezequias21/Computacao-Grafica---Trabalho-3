#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED

#include <GL/glut.h>
#include "polygon.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef struct{
    Point center;
    vector<Point> points_collision;
}Points_nave;

void draw_nave(int,int);
Points_nave load_points_collision_nave(int,int);
void print_nave_points_collision(Points_nave);
bool collision(vector<Polygon_convex>,Points_nave);

#endif
