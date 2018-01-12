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

map<double,int>  evualuar_movimientos(vector <int> movimiento_posible, map< pair<int,int>,  pair<double,double> > distancias, int nodo, int alfa, int beta){
      map<double,int>  Probabilidad;
      vector<double> temp;  
      double probabilidad_i;
      pair <int,int> relacion_ij;
      pair <double,double> valores_ij; 
     
      double sumatoria=0;
  
      for (int i = 0; i < movimiento_posible.size(); ++i){
         relacion_ij.first=nodo;
         relacion_ij.second=movimiento_posible[i];

         valores_ij=distancias[relacion_ij]; 
         probabilidad_i=pow(valores_ij.second,alfa)*pow(valores_ij.first,beta);

         sumatoria+=probabilidad_i;
         temp.push_back( probabilidad_i );
      }
      
      for (int i = 0; i < movimiento_posible.size(); ++i){
         Probabilidad.insert( pair<double,int>(temp[i]/sumatoria,i ) );
      }
      return Probabilidad;
}


int movimiento_hormiga(map<double,int>  Probabilidad){
  int pos=1;
  int seleccion= rand () % 5 + 1;
  map<double, int>::reverse_iterator rit;
  if(Probabilidad.size() >= 5 )
    for (rit=Probabilidad.rbegin(); rit!=Probabilidad.rend(); ++rit){
      if(pos<seleccion)
        pos++;
      else return rit->second;
    }
  else{
    rit=Probabilidad.rbegin();
    return rit->second;
  }
}

map< pair<int,int>,  pair<double,double> > evaporacion (map< pair<int,int>,  pair<double,double> > distancias,double ro){
  
  for ( map<pair<int,int>,  pair<double,double> >::iterator it=distancias.begin(); it!=distancias.end(); ++it){
    distancias[it->first].second*=(1-ro);
  }
  
  return distancias;
}

double valor_solucion(vector<int>  solucion,map< pair<int,int>,  pair<double,double> > distancias){
  double valor=0;
  pair<int,int> relacion_ij;
  for (int i = 0; i < solucion.size(); ++i){
      relacion_ij.first=solucion[i]; relacion_ij.second=solucion[i+1];
      valor+=distancias[relacion_ij].first;

  }
  return valor;
}

map< pair<int,int>,  pair<double,double> > deposito (vector<int>  solucion, map< pair<int,int>,  pair<double,double> > distancias){
  pair<int,int> relacion_ij;
  pair<int,int> relacion_ji;
  
  double valorSolucion= valor_solucion(solucion,distancias);
  
  for (int i = 0; i < solucion.size()-1; ++i){
    relacion_ij.first=solucion[i]; relacion_ij.second=solucion[i+1];
    relacion_ji.first=solucion[i+1];  relacion_ji.second=solucion[i]; 
    distancias[relacion_ij].second*=(1.5);
    distancias[relacion_ji].second*=(1.5);
  }
  return distancias;
}

