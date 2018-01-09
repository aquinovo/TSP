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
#include <algorithm> 

using namespace std;

vector <float> evualuar_movimientos(vector <int> movimiento_posible, map< pair<int,int>,  pair<float,float> > distancias, int nodo, int alfa, int beta){
      vector<float> Probabilidad;  
      float probabilidad_i;
      pair <int,int> relacion_ij;
      pair <float,float> valores_ij; 
      //obtener la sumatoria hacia los nodos posibles
      float sumatoria=0;
  
      for (int i = 0; i < movimiento_posible.size(); ++i){
         relacion_ij.first=nodo;
         relacion_ij.second=movimiento_posible[i];

         valores_ij=distancias[relacion_ij]; 
         probabilidad_i=pow(valores_ij.second,alfa)*pow(valores_ij.first,beta);

         sumatoria+=probabilidad_i;
         Probabilidad.push_back( probabilidad_i );
      }
      
      for (int i = 0; i < movimiento_posible.size(); ++i){
            Probabilidad[i]/=sumatoria;
      }
      return Probabilidad;
}

bool myfunction (int i,int j) { return (i<j); }
int movimiento_hormiga(vector<float> Probabilidad){
  int pos=0;
  sort(Probabilidad.begin(),Probabilidad.end(),myfunction);

  for (int i = 0; i < Probabilidad.size(); ++i){
    cout<<Probabilidad[i]<<endl;
  }
  return pos;
}

vector <int> hormiga(map< pair<int,int>,  pair<float,float> > distancias, int num_nodes, int alfa, int beta, int num_hormigas){
  vector <int> movimiento_posible;
  vector<float> Probabilidad;
  vector <int> solucion;
  int nodo,pos_inicial;

  for (int i = 0; i < num_nodes; ++i){
    movimiento_posible.push_back(i+1);
  }

  pos_inicial=rand() % movimiento_posible.size();
  nodo=movimiento_posible[pos_inicial];
  movimiento_posible.erase (movimiento_posible.begin()+pos_inicial);
  solucion.push_back(nodo);



  Probabilidad = evualuar_movimientos(movimiento_posible, distancias, nodo,alfa,beta);
  movimiento_hormiga(Probabilidad); 
    



  return solucion;
}
