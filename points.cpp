#include <GL/glut.h>
#include "polygon.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

/*O usuário começa com três vidas, quando chegar em zero ele perde. Cada colisão
decrementa em 0.06 sua vida. É feito desta forma para facilitar a jogabilidade. Quando
o personagem colide com algum asteróide é dectado um colisão,assim usuário precisa
retornar para a posição fora do asteróide. Esse tempo gasto é suficiente para gerar várias
colisões, o que esgotaria sua vida muito rapidamente*/
bool set_life(float &life){
    life=life - 0.06;
    if(((int)life)<=0)
        return true;
    else
        return false;
}
/*Cada asteróide destruído aumenta a pontução do usuário em 10*/
void gain_points(unsigned int &point){
    point=point+10;

}


