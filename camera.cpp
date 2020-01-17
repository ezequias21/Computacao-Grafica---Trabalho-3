#include <GL/glut.h>
#include <iostream>


void move_camera(int width, int height,int columns, float &camera_bottom,  float &camera_up,float passo, int limite){

    if(((int)camera_up) == limite){
        return;
    }

    glViewport(0.0, 0.0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0,columns,camera_bottom+=passo, camera_up+=passo, -1.0, 1.0);

}

void reset_camera(int width, int height,int columns, int rows){

    glViewport(0.0, 0.0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0,columns,0.0,rows, -1.0, 1.0);
}
