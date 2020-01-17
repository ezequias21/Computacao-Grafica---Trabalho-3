#include "polygon.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "points.h"
using namespace std;

/*Após o clique do mouse, verifica se o clique está sobre algum asteróide. Caso sim,
o asteróide é destruído.*/

void destruct_rocks(Point point, vector<Polygon_convex> &polygon_convex, unsigned int &points){


   for(unsigned int i=0; i<polygon_convex.size();i++){
        if(!intercpt(point, polygon_convex[i].polygon)){
              polygon_convex.erase(polygon_convex.begin()+i);
              gain_points(points);
              printf("Exclui rocha\n");
              break;
        }
   }

}
