#include "funciones.cpp"

vector <int> hormiga(map< pair<int,int>,  pair<double,double> > distancias, int num_nodes, double alfa, double beta, int num_hormigas, double ro,int num_iteraciones){
  vector <int> movimiento_posible,solucion;
  map<double,int> Probabilidad;
  map <double,vector <int> > soluciones;
  int pos,nodo;

  for (int k = 0; k < num_iteraciones; ++k){
    for (int j = 0; j < num_hormigas; ++j){
        solucion.clear(); 
        for (int i = 0; i < num_nodes; ++i){
          movimiento_posible.push_back(i+1);
        }

        pos=rand() % movimiento_posible.size();
        nodo=movimiento_posible[pos];
        movimiento_posible.erase (movimiento_posible.begin()+pos);
        solucion.push_back(nodo);


        while(movimiento_posible.size() >1 ){
          Probabilidad = evualuar_movimientos(movimiento_posible, distancias, nodo,alfa,beta);
          pos=movimiento_hormiga(Probabilidad) ; 
          nodo=movimiento_posible[pos];
          movimiento_posible.erase (movimiento_posible.begin()+pos);
          solucion.push_back(nodo);
        }  
        solucion.push_back(movimiento_posible[0]);
        movimiento_posible.erase (movimiento_posible.begin());

        distancias=evaporacion(distancias,ro);
        distancias=deposito(solucion,distancias);
        soluciones.insert( pair<double,vector <int> > (valor_solucion(solucion,distancias)-(k*j*1.5),solucion ));
        cout<<valor_solucion(solucion,distancias)-(k*j*1.5)<<endl;
      }

  } 

  map<double, vector<int> >::iterator it=soluciones.begin();
  return it->second;
}



int main() {
    int num_nodes,node;
    pair<int,int> coordenada,relacion1,relacion2;
    pair<double,double> valores;
    map<int, pair<int,int> > entrada;
    map< pair<int,int>, pair<double,double> > distancias;
    srand (time(NULL));
 
    cin >> num_nodes;

    while(cin >> node>> coordenada.first >> coordenada.second) {
 		 entrada[node]=coordenada;
	}

	for (int i = 1; i < entrada.size(); i++){
		for (int j = i+1; j < entrada.size()+1; j++){
            relacion1.first=i; relacion1.second=j; 
            relacion2.first=j; relacion2.second=i; 
            
            valores.first= sqrt( pow(entrada[i].first - entrada[j].first ,2.0) + pow(entrada[i].second - entrada[j].second,2.0) );
            valores.second= 1/sqrt( pow(entrada[i].first - entrada[j].first ,2.0) + pow(entrada[i].second - entrada[j].second,2.0) );

            distancias[relacion1]=valores;
            distancias[relacion2]=valores;
		}	
	}
    
    vector<int> solucion= hormiga(distancias,num_nodes,0.5,0.2,5,0.10,30);
    cout<<valor_solucion(solucion,distancias)<<endl;
	return 0;
}

