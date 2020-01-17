#include <GL/glut.h>
#include "polygon.h"
#include <stdio.h>
#include "nave.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/*Função que desenha o foguete com base em ponto central*/
void draw_nave(int x, int y){

    //Desenha o corpo do foguete
    glColor3f(0.600000,0.196100,0.800000);
    glBegin(GL_POLYGON);
        glVertex2i(x-3, y+3);
        glVertex2i(x-3,y-3);
        glVertex2i(x+3,y-3);
        glVertex2i(x+3,y+3);
        glVertex2i(x,y+6);
        glVertex2i(x-3,y+3);
    glEnd();

    //Desenha o bico do foguete
    glColor3f(0.800000,0.196100,0.196100);
    glBegin(GL_TRIANGLES);
        glVertex2i(x-1,y+5);
        glVertex2i(x+1,y+5);
        glVertex2i(x,y+6);
    glEnd();

    //Desenha a janela do foguete
    glColor3f(0.000000,1.000000,1.000000);
    glBegin(GL_QUADS);
        glVertex2i(x-2,y+2);
        glVertex2i(x+2,y+2);
        glVertex2i(x+2,y+3);
        glVertex2i(x-2,y+3);
    glEnd();


    //Desenha o cano do foguete
    glColor3f(0.658800,0.658800,0.658800);
    glPushMatrix();
    glTranslated(0,-6,0);
    glBegin(GL_QUADS);
        glVertex2i(x-2,y+2);
        glVertex2i(x+2,y+2);
        glVertex2i(x+2,y+3);
        glVertex2i(x-2,y+3);
    glEnd();
    glPopMatrix();

    //Desenha asa direita
    glColor3f(1.0,0.949,0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(x-6,y-2);
        glVertex2i(x-3,y-2);
        glVertex2i(x-3,y+1);
    glEnd();

    //Desenha asa esquerda
    glBegin(GL_TRIANGLES);
        glVertex2i(x+3,y-2);
        glVertex2i(x+6,y-2);
        glVertex2i(x+3,y+1);
    glEnd();

   //Desenha o fogo do foquete
    glColor3f(1.000000,0.498000,0.000000);
    glBegin(GL_POLYGON);
        glVertex2i(x-2,y-4);
        glVertex2i(x-3,y-5);
        glVertex2i(x-2,y-5);
        glVertex2i(x,y-7);
        glVertex2i(x+2,y-5);
        glVertex2i(x+3,y-5);
        glVertex2i(x+2,y-4);
        glVertex2i(x-2,y-4);
    glEnd();


}
Points_nave load_points_collision_nave(int x, int y){

    Points_nave points_nave;
    Point point;

    points_nave.center.x = x;
    points_nave.center.y =y;


    /*A seguir é adicionado os pontos de colisão do nave.
    Ou seja, os pontos que serão usados para verificar se a nave colidiu
    com algum objeto
    */

    point.x = x-3;
    point.y = y+3;
    points_nave.points_collision.push_back(point);

    point.x = x-3;
    point.y = y+1;
    points_nave.points_collision.push_back(point);

    point.x = x-6;
    point.y = y-2;
    points_nave.points_collision.push_back(point);

    point.x = x-3;
    point.y = y-3;
    points_nave.points_collision.push_back(point);

    point.x = x-2;
    point.y = y-4;
    points_nave.points_collision.push_back(point);

    point.x =x-3;
    point.y = y-5;
    points_nave.points_collision.push_back(point);

    point.x = x-2;
    point.y = y-5;
    points_nave.points_collision.push_back(point);

    point.x = x;
    point.y = y-7;
    points_nave.points_collision.push_back(point);

    point.x = x+2;
    point.y = y-5;
    points_nave.points_collision.push_back(point);

    point.x = x+3;
    point.y = y-5;
    points_nave.points_collision.push_back(point);

    point.x = x+3;
    point.y = y-3;
    points_nave.points_collision.push_back(point);

    point.x = x+6;
    point.y = y-2;
    points_nave.points_collision.push_back(point);

    point.x = x+3;
    point.y = y+1;
    points_nave.points_collision.push_back(point);

    point.x = x+3;
    point.y = y+3;
    points_nave.points_collision.push_back(point);

    point.x = x;
    point.y = y+6;
    points_nave.points_collision.push_back(point);

    return points_nave;
}
/*Função para imprimir na tela o pontos de colisão da nave*/
void print_nave_points_collision(Points_nave points_nave){
    cout << "Vertices" <<endl;
    cout << "Tamanho = " << points_nave.points_collision.size()<<endl;
    for(int i=0; i<points_nave.points_collision.size();i++){
        cout<<"x : " << points_nave.points_collision[i].x << " y : " <<points_nave.points_collision[i].y << endl;
    }

}


/*Função que verifica se ouve colisão entre a nave e algum asteróide. Caso houve
colisão a função retorna verdadeiro*/
bool collision(vector<Polygon_convex> polygon_convex,Points_nave points_nave){

    for(unsigned int i=0; i<polygon_convex.size();i++){
        for(unsigned int j=0;j<points_nave.points_collision.size();j++){
            if(!intercpt(points_nave.points_collision[j], polygon_convex[i].polygon)){
               printf("Colidiu");

               return true;
            }
    }
}
return false;
}
