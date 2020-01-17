#include <GL/glut.h>
#include <vector>
#include "polygon.h"
#include "draw.h"
#include "nave.h"
#include "mouse.h"
#include "tela.h"
#include "camera.h"
#include "points.h"
#define FPS 50
#define ORTHO_LIMIT 200
#define MAX_ROW 200
using namespace std;

int COLUMNS = 100;
int ROWS = 100;

int minAxisX = 0;
int maxAxisX = COLUMNS;
int minAxisY = 0;
int maxAxisY = MAX_ROW;
char myScore[5];

float positionX = 28;
float positionY = 17;
unsigned int points = 0;
float life = 3.0;
bool context = false;
bool win = false;
Points_nave nave;
Point p;
int acumulator=0;
Point coord_mouse;

float camera_bottom = 0;
float camera_up = 100;


vector<Polygon_convex> polygon_convex; //Contém os asteróides do jogo
vector<Star> stars;                    //Contém as estrelas
vector<Point> final_menu_coord;        //Cotém as coordenadas do menu


void resize_window(int width, int height){

    glViewport(0.0, 0.0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0,COLUMNS, 0.0, ROWS, -1.0, 1.0);

   // glutInitWindowSize(700,700);

}
/*Está função exibe o status do jogo durante a partida*/
void setText(){


    char texto1[10] = "Life: ";
    char texto2[10];
    sprintf(texto2,"%d",(int)life);
    strcat(texto1, texto2);
    desenha_texto(texto1,10,camera_up-5.0);

    char texto3[10] = "Points: ";
    sprintf(texto2,"%d",points);
    strcat(texto3,texto2);
    desenha_texto(texto3,80,camera_up-5.0);

}


void draw(){
    glClear(GL_COLOR_BUFFER_BIT);

    /*Verifica se o usuário ainda pode jogar. O usuário possui três vidas
    que quando exauridas a partida acaba.
    */
    if((int(life))<=0){


     reset_camera(700,700,100,100);
     final_menu(final_menu_coord);   //Exite o botão "Try Again"
     context = true;

    }
      if(win== true){

        reset_camera(700,700,100,100);
        menu_play_again(final_menu_coord,myScore);     //Exibe o botão "Play Again"

    }else
        if(context == false){
            draw_stars(stars);
            draw_polygon(polygon_convex);
            draw_nave(positionX,positionY);
            rotate_all_polygons(polygon_convex);

            if(collision(polygon_convex,nave))
                set_life(life);

            move_camera(700,700,100,camera_bottom,camera_up,0.2, ORTHO_LIMIT);
            setText();

            /*O usuário vence quando chegar no final do mapa*/
            if(positionY > MAX_ROW - 10){
                win = true;
                sprintf(myScore,"%d",points);


            }


    }
    glutSwapBuffers();
}


void keyboard_special(int key, int x, int y){

    /*Utiliza as teclas especias UP, DOWN, LEFT E RIGHT para controlar o personagem.
    O personagem sÓ movimentá-se, caso ele esteja dentro dos limites do mapa do jogo.
    */
    switch(key){
        case GLUT_KEY_UP:
            if((int)positionY < maxAxisY)
                positionY++;
            break;

        case GLUT_KEY_DOWN:
             if((int)positionY> minAxisY)
                positionY--;
            break;

        case GLUT_KEY_LEFT:
             if((int)positionX> minAxisX)
                positionX--;
            break;
        case GLUT_KEY_RIGHT:
                if((int)positionX < maxAxisX)
                positionX++;

            break;
    }
    p.x = positionX;
    p.y = positionY;
    /*A função a seguir é chamada para realizar a translação do personagem para
    suas novas coordenadas.*/
    nave = load_points_collision_nave(positionX, positionY);

}

void time(int){

    glutPostRedisplay();
    glutTimerFunc(1000/FPS,time,0);

}
void mouse(int button, int state, int x, int y){
    Point point;
    point.x = x/7;
    point.y = (((700-y)*100)/700)+camera_bottom;

    printf("%.2f", point.y);
    if (button == GLUT_LEFT_BUTTON){
        /*Um asteróide só é destruído depois de 10 cliques consecutivos. Quer dizer,
        depois de 10 cliques consecutivos é testado se o clique do mouse está contido
        dentro de algum asteróide, caso verdadeiro o asteróide é destruído*/

        if(acumulator==10){
            /*É realizado um mapeamento entre o sistema SRD para o sistema SRU*/
            coord_mouse.x = x/7;
            coord_mouse.y = (((700-y)*100)/700)+camera_bottom;
            destruct_rocks(coord_mouse, polygon_convex, points);
            acumulator=0;

        }else{
            acumulator++;
        }

        //Verifica se o usuario clicou em alguns dos menus. Caso tenha clicado
        //O jogo é iniciado
        if((win==true ||context==true) && (intercpt(point,final_menu_coord))){
            life = 3.9;
            points = 0;
            context = false;
            win = false;
            camera_up = ROWS;
            camera_bottom = 0.0;
            positionX = 18.0;
            positionY = 23.0;
            polygon_convex.clear();
            define_polygon_teste(polygon_convex);

        }

    }

    glutPostRedisplay();


}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);


    define_polygon_teste(polygon_convex); //carrega os asteróides do jogo
    nave = load_points_collision_nave(positionX, positionY);  //carrega os pontos de colisão da nave
    stars = load_stars();  //inicializa as estrelas

    glutCreateWindow("Atividade 3");
    init();
    initMenu(final_menu_coord);


    glutReshapeFunc(resize_window);
    glutDisplayFunc(draw);
    glutSpecialFunc(keyboard_special);
    glutMouseFunc(mouse);
    glutTimerFunc(0,time,0);


    glutMainLoop();

    return EXIT_SUCCESS;
}
