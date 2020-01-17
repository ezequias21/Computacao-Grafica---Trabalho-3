#include <GL/glut.h>
#include "polygon.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include "draw.h"
#define STAR 350
using namespace std;


#define COLUMNS 100
#define ROWS 100





void define_polygon_teste(vector<Polygon_convex> &polygons){

    Point center;
    Color color;
    Polygon_convex polygon_convex;

    color.red =0.647100;
    color.green=  0.164700;
    color.blue =  0.164700;

    center.x = 10.0;
    center.y = 10.0;

    polygon_convex = create_polygon(8,center,6, 1, color);
    polygons.push_back(polygon_convex);


    center.x = 30.0;
    center.y = 70.0;

    polygon_convex = create_polygon(3,center,6,-1, color);
    polygons.push_back(polygon_convex);

    color.red =0.372600;
    color.green= 0.623500;
    color.blue = 0.623500;
    center.x = 80.0;
    center.y = 60.0;

    polygon_convex = create_polygon(5,center,10,-1, color);
    polygons.push_back(polygon_convex);

    color.red =0.372600;
    color.green= 0.623500;
    color.blue = 0.623500;
    center.x = 70.0;
    center.y = 120.0;

    polygon_convex = create_polygon(5,center,20,-1, color);
    polygons.push_back(polygon_convex);


    center.x = 80.0;
    center.y = 10.0;

    polygon_convex = create_polygon_no_convex1(center,0.3, color);
    polygons.push_back(polygon_convex);


    color.red =0.137300;
    color.green= 0.556900;
    color.blue = 0.137300;

    center.x = 25.0;
    center.y = 160.0;

    polygon_convex = create_polygon_no_convex2(center,0.3, color);
    polygons.push_back(polygon_convex);

    center.x = 70.0;
    center.y = 180.0;

    polygon_convex = create_polygon_no_convex1(center,0.4, color);
    polygons.push_back(polygon_convex);

    center.x = 10.0;
    center.y = 175.0;


    polygon_convex = create_polygon_no_convex1(center,0.2, color);
    polygons.push_back(polygon_convex);

    center.x = 18.0;
    center.y = 123.0;

    polygon_convex = create_polygon_no_convex1(center,0.3, color);
    polygons.push_back(polygon_convex);

    center.x = 15.0;
    center.y = 182.0;

    polygon_convex = create_polygon_no_convex2(center,0.2, color);
    polygons.push_back(polygon_convex);


    center.x = 15.0;
    center.y = 160.0;

    polygon_convex = create_polygon_no_convex2(center,0.2, color);
    polygons.push_back(polygon_convex);

    center.x = 20.0;
    center.y = 175.0;

    polygon_convex = create_polygon_no_convex4(center,0.4, color);
    polygons.push_back(polygon_convex);


    color.red =0.372600;
    color.green= 0.623500;
    color.blue = 0.623500;
    center.x = 50.0;
    center.y = 170.0;

    polygon_convex = create_polygon(6,center,15,-1, color);
    polygons.push_back(polygon_convex);

    center.x = 80.0;
    center.y = 10.0;

    polygon_convex = create_polygon_no_convex1(center,0.3, color);
    polygons.push_back(polygon_convex);

    center.x = 11.0;
    center.y = 36.0;

    polygon_convex = create_polygon_no_convex2(center,0.3, color);
    polygons.push_back(polygon_convex);



    color.red =0.137300;
    color.green= 0.556900;
    color.blue = 0.137300;

    center.x = 50.0;
    center.y = 10.0;

    polygon_convex = create_polygon_no_convex2(center,0.3, color);
    polygons.push_back(polygon_convex);


    color.red =0.137300;
    color.green= 0.556900;
    color.blue = 0.137300;

    center.x = 50.0;
    center.y = 50.0;

    polygon_convex = create_polygon_no_convex2(center,0.3, color);
    polygons.push_back(polygon_convex);


    color.red =0.137300;
    color.green= 0.556900;
    color.blue = 0.137300;

    center.x = 80.0;
    center.y = 190.0;

    polygon_convex = create_polygon_no_convex2(center,0.3, color);
    polygons.push_back(polygon_convex);

    center.x = 15.0;
    center.y = 38.0;

    polygon_convex = create_polygon_no_convex1(center,0.5, color);
    polygons.push_back(polygon_convex);



    center.x = 88.0;
    center.y = 75.0;

    polygon_convex = create_polygon_no_convex3(center,0.2, color);
    polygons.push_back(polygon_convex);

    center.x = 80.0;
    center.y = 75.0;

    polygon_convex = create_polygon_no_convex2(center,-1.0, color);
    polygons.push_back(polygon_convex);


    center.x = 83.0;
    center.y = 132.0;

    polygon_convex = create_polygon_no_convex4(center,0.5, color);
    polygons.push_back(polygon_convex);



    color.red =0.137300;
    color.green= 0.556900;
    color.blue = 0.137300;

    center.x = 20.0;
    center.y = 80.0;


    polygon_convex = create_polygon_no_convex3(center,0.3, color);
    polygons.push_back(polygon_convex);


    center.x = 50.0;
    center.y = 70.0;

    polygon_convex = create_polygon_no_convex4(center,-0.2, color);
    polygons.push_back(polygon_convex);


    center.x = 60.0;
    center.y = 75.0;

    polygon_convex = create_polygon_no_convex4(center,-0.2, color);
    polygons.push_back(polygon_convex);

    center.x = 50.0;
    center.y = 140.0;

    polygon_convex = create_polygon_no_convex3(center,-0.2, color);
    polygons.push_back(polygon_convex);

    center.x = 25.0;
    center.y = 140.0;

    polygon_convex = create_polygon_no_convex4(center,0.3, color);
    polygons.push_back(polygon_convex);

}


/*Calcula a coordenada de cada estrela do mapa utilizando aleatoriamente.
A espessura do pincel para desenhar a estrela, na qual será usado para gerar
a percepção de distancia também é calculado*/
vector<Star> load_stars(){

  vector<Star> stars;
    Star star;
    float sizePoint;
    srand(time(NULL));
    for(int i=0;i<STAR;i++){

        star.pointSize = sizePoint = 0.01 + (rand()% 4);
        star.point.x=  (rand() % COLUMNS);
        star.point.y =  rand() % (ROWS+ROWS);
        stars.push_back(star);
    }

    return stars;
}
/*Desenha as estrelas*/
void draw_stars(vector<Star> stars){

    glColor3f(1.0f,1.0f,1.0f);
    for(int i=0; i<stars.size();i++){

        glPointSize(stars[i].pointSize);
        glBegin(GL_POINTS);
        glVertex2i(stars[i].point.x, stars[i].point.y);

    glEnd();
    }

}

/*Todos os asteróides são desenhados de acordo com suas características próprias*/
void draw_polygon(vector<Polygon_convex> polygons){

    for(unsigned int i=0; i<polygons.size();i++){

        glColor3f(polygons[i].color.red,polygons[i].color.green,polygons[i].color.blue);
        glBegin(GL_POLYGON);

        for(int j =0; j< polygons[i].polygon.size();j++){
            glVertex2f(polygons[i].polygon[j].x, polygons[i].polygon[j].y);
        }
        glEnd();

        glColor3f(0.658800,0.658800,0.658800);
        glLineWidth(3.0f);

        glBegin(GL_LINE_LOOP);
        for(int j =0; j< polygons[i].polygon.size();j++){
            glVertex2f(polygons[i].polygon[j].x, polygons[i].polygon[j].y);
        }
        glEnd();

}
}

