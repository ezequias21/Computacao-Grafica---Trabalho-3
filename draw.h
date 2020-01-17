#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "polygon.h"
#include <iostream>
#include <vector>
using namespace std;

typedef struct{
  Point point;
  float pointSize;
}Star;



void define_polygon_teste(vector<Polygon_convex> &);
void draw_polygon(vector<Polygon_convex>);
vector<Star> load_stars();
void draw_stars(vector<Star>);


#endif // DRAW_H_INCLUDED
