#include <vector>
#include <map>
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <queue>
#include <sys/time.h>
#include <fstream>
#include <set>

using namespace std;

vector <float> evualuar_movimientos( vector <int> movimiento_posible,vector <int> solucion,map<int, pair<int,int> > entrada, map< pair<int,int>,  pair<float,float> > distancias, int nodo, int alfa, int beta){
      
      //obtener la sumatoria del recorrido total    
}

vector <int> hormiga(map<int, pair<int,int> > entrada, map< pair<int,int>,  pair<float,float> > distancias, int num_nodes, int alfa, int beta){
  vector <int> movimiento_posible;
  vector <int> solucion;
  int nodo,pos;

  for (int i = 0; i < num_nodes; ++i){
    movimiento_posible.push_back(i+1);
  }

  pos=rand() % movimiento_posible.size();
  nodo=movimiento_posible[pos];
  movimiento_posible.erase (movimiento_posible.begin()+pos);
  
  solucion.push_back(nodo);

  evualuar_movimientos(movimiento_posible,solucion,entrada, distancias, nodo,alfa,beta);

  



  return solucion;
}
