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
vector <int> crear_solucion(map<int, pair<int,int> > entrada, map< pair<int,int>,  pair<float,float> > distancias, int num_nodes){
  vector <int> nodos_disponibles;
  vector <int> solucion;
  int nodo;

  for (int i = 0; i < num_nodes; ++i){
    nodos_disponibles.push_back(i+1);
  }


  while( nodos_disponibles.size()>=0 ){
    nodo=rand()%nodos_disponibles.size();
    solucion.push_back(nodos_disponibles[nodo]);
    nodos_disponibles.erase(nodos_disponibles.begin()+nodo);
  }

  return solucion;
}