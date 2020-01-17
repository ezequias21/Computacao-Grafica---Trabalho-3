#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED

#include "polygon.h"
#include <iostream>
#include <vector>


void desenha_texto(char*,float, float);
void draw_text_bitmaps(void *, char *);
void initMenu(vector<Point> &);
void draw_button(vector<Point>);
void final_menu(vector<Point>);
void menu_play_again(vector<Point>, char *);

#endif // TELA_H_INCLUDED
