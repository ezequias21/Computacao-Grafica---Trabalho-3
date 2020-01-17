#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED
#include <vector>
using namespace std;

 void init();

typedef struct{
    int red;
    float green;
    float blue;
}Color;

typedef struct{

	float x;
	float y;

}Point;

typedef struct{

    vector<Point> polygon;
    Point center;
    int distance_center_aresta;
    Color color;
    float rotation_angle_radians;

}Polygon_convex;


int max(int,int);
int min(int,int);
int ray_intersect_segments(Point,Point,Point);
Polygon_convex create_polygon(int,Point,int,int,Color);
void print_coord_polygon(vector<Point>);
void print_polygon(Polygon_convex);
int isOdd(int);
int intercpt(Point,vector<Point>);
Polygon_convex rotate_polygon(Polygon_convex);
void rotate_all_polygons(vector<Polygon_convex> &);
Polygon_convex create_polygon_no_convex1(Point, float, Color);
Polygon_convex create_polygon_no_convex2(Point, float, Color);
Polygon_convex create_polygon_no_convex3(Point, float, Color);
Polygon_convex create_polygon_no_convex4(Point, float, Color);
 #endif
