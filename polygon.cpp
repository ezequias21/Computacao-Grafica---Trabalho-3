#include <GL/glut.h>
#include "polygon.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#define true 1
#define false 0
using namespace std;


void init(){

    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int max(int number1,int number2){
	if(number1>number2)
		return number1;
	else
		return number2;
}

int min(int number1,int number2){
	if(number1<number2)
		return number1;
	else
		return number2;
}
/*
A colisão entre dois objetos é tratada da seguinte forma. Queremos determinar se um
ponto P colidiu com alguma figura plana. Uma reta r é traçada horizontalmente a partir de P
e prolongada até a intersecção do ponto mais distante da figura plana. Conta-se então,
a quantidade de intersecções que a reta r faz na figura. Caso par, P não colidiu,
caso ímpar P colidiu.

O algoritmo que implenta tal tarefa remete aos primeiros problemas encontrados na computação
gráfica, chamado de Algoritmo Ray casting. Tal algoritmo pode ser encontrado no domínio
<https://rosettacode.org/wiki/Ray-casting_algorithm>
*/


int ray_intersect_segments(Point P, Point A, Point B){

	float m_blue, m_red;
	if(A.y == P.y){
 		P.y = P.y + 0.0001;
	}

	if(P.y < A.y || P.y > B.y){
		return false;
	}
	else if (P.x > max(A.x, B.x)){
		return false;
	}
	else if((P.x <= min(A.x, B.x))){
 		return true;
	}
 	else if(A.x != B.x){
 		m_red = (B.y - A.y)/(B.x - A.x);
 	}

	else{
		return false;

	}

    if(A.x != P.x)
    	m_blue = (P.y - A.y)/(P.x - A.x);

     else{
        return false;
     }

     if (m_blue >= m_red ){
       return true;
     }

     else{
       return false;
    }
}
/*Cria um polígono convexo, ou seja um asteróide. Um asteróide contém informações
como números de lados, centro, distancia da aresta ao centro, ângulo de fase e cor
O ângulo de fase determina a velocidade do giro do asteróide*/
Polygon_convex create_polygon(int sides, Point center, int distance_center_aresta, int phase, Color color){


	double angle_aresta = 360/sides;
	double angle_phase = ((phase*3.1415)/180);
	angle_aresta = ((angle_aresta*3.1415)/180);

	double angle_initial=0;
	Point p;
	vector<Point> points_polygon;

	Polygon_convex polygon_convex;
	polygon_convex.rotation_angle_radians = angle_phase;
	polygon_convex.center.x = center.x;
	polygon_convex.center.y = center.y;
	polygon_convex.distance_center_aresta = distance_center_aresta;
	polygon_convex.color = color;

	for(int i=0; i<sides ;i++){
		p.x = center.x + distance_center_aresta*(cos(angle_initial));
		p.y = center.y + distance_center_aresta*(sin(angle_initial));
		angle_initial+=angle_aresta;
		points_polygon.push_back(p);
	}
	polygon_convex.polygon = points_polygon;
	return polygon_convex;
}


void print_coord_polygon(vector<Point> points_polygon){


	for(vector<Point>::iterator i = points_polygon.begin(); i!=points_polygon.end(); i++){
		cout << (*i).x;
		cout << (*i).y <<endl;
	}
}

int isOdd(int value){

	if((value % 2)==0){
		return true;
	}
	else
		return false;
}

/*Verifica se um ponto colide com um asteróide*/
int intercpt(Point point, vector<Point> polygon){

	int count = 0;
	int i;
	for(unsigned i=0; i<polygon.size()-1;i++){

		if(polygon[i].y < polygon[i+1].y){
			count += ray_intersect_segments(point, polygon[i], polygon[i+1]);
		}else
		    count += ray_intersect_segments(point, polygon[i+1], polygon[i]);

	}
	i = polygon.size()-1;
    //Liga o último ponto ao ponto inicial
    if(polygon[i].y < polygon[0].y){
			count += ray_intersect_segments(point, polygon[i], polygon[0]);
		}else
		    count += ray_intersect_segments(point, polygon[0], polygon[i]);

	if(isOdd(count))
		return true;
	else
  		return false;

}
/*Rotaciona os asteróides com base no seu ângulo de fase. Todos os pontos de um
asteróide são rotacionados igualmente com base no ângulo de fase*/
Polygon_convex rotate_polygon(Polygon_convex polygon_convex){



	float angle_phase = polygon_convex.rotation_angle_radians;


        float referenceX = polygon_convex.center.x, referenceY = polygon_convex.center.y;
        float coordX, coordY;
        for(unsigned int i = 0; i < polygon_convex.polygon.size(); i++){

            coordX = (polygon_convex.polygon[i].x-referenceX)*cos(angle_phase);
            coordX = coordX - (polygon_convex.polygon[i].y-referenceY)*sin(angle_phase);


            coordY = (polygon_convex.polygon[i].y-referenceY)*cos(angle_phase);
            coordY = coordY +  (polygon_convex.polygon[i].x-referenceX)*sin(angle_phase);


            coordX +=referenceX;
            coordY +=referenceY;

            polygon_convex.polygon[i].x = coordX;
            polygon_convex.polygon[i].y = coordY;

        }

	return polygon_convex;
}
//Rotaciona todos os asteróides
void rotate_all_polygons(vector<Polygon_convex> &polygons_convex){

    for(unsigned int i = 0; i < polygons_convex.size();i++){
        polygons_convex[i] = rotate_polygon(polygons_convex[i]);
    }
}

void print_polygon(Polygon_convex polygon_convex){
    for(unsigned int i=0;i<polygon_convex.polygon.size();i++){
        printf("x = %.2f y = %.2f", polygon_convex.polygon[i].x, polygon_convex.polygon[i].y);
    }
    printf("\n");
}

/*As rotinas a seguir cria um póligono não convexo para representar um asteróide
com mais detalhes. Os póligonos a seguir são construídos com base em um ponto central*/

Polygon_convex create_polygon_no_convex1(Point center, float phase, Color color){

    Point coord;
    Polygon_convex polygon_convex;
    vector<Point> polygon;
    double angle_phase = ((phase*3.1415)/180);

    int x = (int)center.x;
    int y = (int)center.y;

    coord.x = x;
    coord.y = y+4;
    polygon.push_back(coord);

    coord.x = x-2;
    coord.y = y+5;
    polygon.push_back(coord);

    coord.x = x-5;
    coord.y = y+1;
    polygon.push_back(coord);

    coord.x = x-5;
    coord.y = y-2;
    polygon.push_back(coord);

    coord.x = x-4;
    coord.y = y-2;
    polygon.push_back(coord);

    coord.x = x-4;
    coord.y = y-4;
    polygon.push_back(coord);

    coord.x = x-2;
    coord.y = y-6;
    polygon.push_back(coord);

    coord.x = x+3;
    coord.y = y-3;
    polygon.push_back(coord);

    coord.x = x+4;
    coord.y = y-4;
    polygon.push_back(coord);

    coord.x = x+6;
    coord.y = y-1;
    polygon.push_back(coord);

    coord.x = x+5;
    coord.y = y+1;
    polygon.push_back(coord);

    coord.x = x+7;
    coord.y = y+3;
    polygon.push_back(coord);

    coord.x = x+7;
    coord.y = y+4;
    polygon.push_back(coord);

    coord.x = x+5;
    coord.y = y+6;
    polygon.push_back(coord);

    coord.x = x+4;
    coord.y = y+6;
    polygon.push_back(coord);

    coord.x = x;
    coord.y = y+4;
    polygon.push_back(coord);
    polygon_convex.polygon = polygon;
    polygon_convex.rotation_angle_radians = angle_phase;
    polygon_convex.color = color;
    polygon_convex.center = center;

    return polygon_convex;
}


Polygon_convex create_polygon_no_convex2(Point center, float phase, Color color){

    Point coord;
    Polygon_convex polygon_convex;
    vector<Point> polygon;
    double angle_phase = ((phase*3.1415)/180);

    int x = (int)center.x;
    int y = (int)center.y;

    coord.x = x-1;
    coord.y = y+8;
    polygon.push_back(coord);

    coord.x = x-5;
    coord.y = y+5;
    polygon.push_back(coord);

    coord.x = x-8;
    coord.y = y;
    polygon.push_back(coord);

    coord.x = x-6;
    coord.y = y-8;
    polygon.push_back(coord);

    coord.x = x-4;
    coord.y = y-10;
    polygon.push_back(coord);


    coord.x = x+6;
    coord.y = y-7;
    polygon.push_back(coord);

    coord.x = x+8;
    coord.y = y+2;
    polygon.push_back(coord);

    coord.x = x+8;
    coord.y = y+4;
    polygon.push_back(coord);

    coord.x = x+6;
    coord.y = y+7;
    polygon.push_back(coord);

    coord.x = x-1;
    coord.y = y+8;
    polygon.push_back(coord);


    polygon_convex.polygon = polygon;
    polygon_convex.rotation_angle_radians = angle_phase;
    polygon_convex.color = color;
    polygon_convex.center = center;

    return polygon_convex;
}

Polygon_convex create_polygon_no_convex3(Point center, float phase, Color color){
        Point coord;
    Polygon_convex polygon_convex;
    vector<Point> polygon;
    double angle_phase = ((phase*3.1415)/180);

    int x = (int)center.x;
    int y = (int)center.y;

    coord.x = x;
    coord.y = y+15;
    polygon.push_back(coord);

    coord.x = x-11;
    coord.y = y+12;
    polygon.push_back(coord);

    coord.x = x-13;
    coord.y = y+7;
    polygon.push_back(coord);


    coord.x = x-17;
    coord.y = y+4;
    polygon.push_back(coord);


    coord.x = x-17;
    coord.y = y;
    polygon.push_back(coord);


    coord.x = x-14;
    coord.y = y-1;
    polygon.push_back(coord);


    coord.x = x-12;
    coord.y = y;
    polygon.push_back(coord);


    coord.x = x-9;
    coord.y = y-1;
    polygon.push_back(coord);


    coord.x = x-6;
    coord.y = y-7;
    polygon.push_back(coord);

    coord.x = x-7;
    coord.y = y-10;
    polygon.push_back(coord);


    coord.x = x-8;
    coord.y = y-16;
    polygon.push_back(coord);

    coord.x = x-6;
    coord.y = y-19;
    polygon.push_back(coord);

    coord.x = x-1;
    coord.y = y-19;
    polygon.push_back(coord);

    coord.x = x+3;
    coord.y = y-14;
    polygon.push_back(coord);

    coord.x = x+6;
    coord.y = y-8;
    polygon.push_back(coord);

    coord.x = x+9;
    coord.y = y-7;
    polygon.push_back(coord);

    coord.x = x+12;
    coord.y = y-8;
    polygon.push_back(coord);

    coord.x = x+13;
    coord.y = y-6;
    polygon.push_back(coord);

    coord.x = x+13;
    coord.y = y-5;
    polygon.push_back(coord);

    coord.x = x+11;
    coord.y = y-2;
    polygon.push_back(coord);

    coord.x = x+14;
    coord.y = y+7;
    polygon.push_back(coord);

    coord.x = x+12;
    coord.y = y+11;
    polygon.push_back(coord);

    polygon_convex.polygon = polygon;
    polygon_convex.rotation_angle_radians = angle_phase;
    polygon_convex.color = color;
    polygon_convex.center = center;

    return polygon_convex;



}

Polygon_convex create_polygon_no_convex4(Point center, float phase, Color color){
    Point coord;
    Polygon_convex polygon_convex;
    vector<Point> polygon;
    double angle_phase = ((phase*3.1415)/180);

    int x = (int)center.x;
    int y = (int)center.y;

    coord.x = x;
    coord.y = y+3;
    polygon.push_back(coord);

    coord.x = x-1;
    coord.y = y+2;
    polygon.push_back(coord);

    coord.x = x-2;
    coord.y = y;
    polygon.push_back(coord);

    coord.x = x-1;
    coord.y = y-1;
    polygon.push_back(coord);

    coord.x = x-1;
    coord.y = y-2;
    polygon.push_back(coord);

    coord.x = x+1;
    coord.y = y-2;
    polygon.push_back(coord);

    coord.x = x+2;
    coord.y = y;
    polygon.push_back(coord);

    coord.x = x+2;
    coord.y = y+2;
    polygon.push_back(coord);

    coord.x = x+1;
    coord.y = y+3;
    polygon.push_back(coord);

    polygon_convex.polygon = polygon;
    polygon_convex.rotation_angle_radians = angle_phase;
    polygon_convex.color = color;
    polygon_convex.center = center;

    return polygon_convex;

}
