#include <GL/glut.h>
#include "polygon.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

/*O usu�rio come�a com tr�s vidas, quando chegar em zero ele perde. Cada colis�o
decrementa em 0.06 sua vida. � feito desta forma para facilitar a jogabilidade. Quando
o personagem colide com algum aster�ide � dectado um colis�o,assim usu�rio precisa
retornar para a posi��o fora do aster�ide. Esse tempo gasto � suficiente para gerar v�rias
colis�es, o que esgotaria sua vida muito rapidamente*/
bool set_life(float &life){
    life=life - 0.06;
    if(((int)life)<=0)
        return true;
    else
        return false;
}
/*Cada aster�ide destru�do aumenta a pontu��o do usu�rio em 10*/
void gain_points(unsigned int &point){
    point=point+10;

}


