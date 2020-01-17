#include <GL/glut.h>
#include "polygon.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

/*Desenha cada caractere no formato bitmap*/
void draw_text_bitmaps(void *font, char *texto){

    while(*texto){
        glutBitmapCharacter(font, *texto++);
    }

}
/*Recebe uma palavra e o a coordenada de onde ela iniciará*/
void desenha_texto(char *word, float x, float y){

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(x,y);
    draw_text_bitmaps(GLUT_BITMAP_HELVETICA_18, word);
}

/*Carrega as coordenadas do botão. O botão que aparece no final do jogo.*/
void initMenu(vector<Point> &final_menu_coord){


 Point point;

 point.x = 35;
 point.y = 50;
 final_menu_coord.push_back(point);

 point.x = 35;
 point.y = 40;
 final_menu_coord.push_back(point);

 point.x = 65;
 point.y = 40;
 final_menu_coord.push_back(point);

 point.x = 65;
 point.y = 50;
 final_menu_coord.push_back(point);


}
/*Desenha o botão*/
void draw_button(vector<Point> button){
       glBegin(GL_POLYGON);
       for(int i=0;i<button.size();i++){
            glVertex2f(button[i].x, button[i].y);
       }
       glEnd();

}
void final_menu(vector<Point> final_menu_coord){

       glColor3f(1.000000,0.498000,0.000000);
       draw_button(final_menu_coord);

       desenha_texto("Game Over!",45, 70);
       desenha_texto("Try Again!",45, 45);

}

void menu_play_again(vector<Point> play_again, char* score){

       glColor3f(1.000000,0.498000,0.000000);
       draw_button(play_again);

       desenha_texto("Congratulations! You Win",35, 75);
       desenha_texto("Your Score: ",40, 70);
       desenha_texto(score, 60,70);
       desenha_texto("Play Again!",45, 45);

}
