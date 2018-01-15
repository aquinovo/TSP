#include "funciones.cpp"

vector <int> hormiga(map< pair<int,int>,  pair<double,double> > distancias, int num_nodes, double alfa, double beta, int num_hormigas, double ro,int num_iteraciones,float probabilidad_seleccion){
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
          pos=movimiento_hormiga(Probabilidad,num_nodes*probabilidad_seleccion) ; 
          nodo=movimiento_posible[pos];
          movimiento_posible.erase (movimiento_posible.begin()+pos);
          solucion.push_back(nodo);
        }  
        solucion.push_back(movimiento_posible[0]);
        movimiento_posible.erase (movimiento_posible.begin());

        distancias=evaporacion(distancias,ro);
        distancias=deposito(solucion,distancias);
        soluciones.insert( pair<double,vector <int> > (valor_solucion(solucion,distancias),solucion ));
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
     //Inicializacion de semilla para generacion de numeros aleatorios
    srand (time(NULL));

    // variables para medir el tiempo de ejecución del algoritmo
    unsigned t0, t1;
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
    
    //Guardar solucion en archivo csv
    ofstream ficheroSalida;
    ficheroSalida.open ("salida/tsp.csv");
    ficheroSalida << "Tiempo,Solución"<<endl; 

    float alfa[]={0.2,0.5,0.8};
    float beta[]={0.2,0.5,0.8};
    int num_hormigas[]={10,30,50};
    float ro[]={0.05,0.2,0.4};
    int num_iteraciones[]={50,150,400};
    float probabilidad_seleccion[]={0.05,0.10,0.25};

    for (int i = 0; i < sizeof(alfa)/sizeof(alfa[0]); i++){
     
        for (int j = 0; j < sizeof(beta)/sizeof(beta[0]); j++){
            
            for (int k = 0; k < sizeof(num_hormigas)/sizeof(num_hormigas[0]); k++){
            
                for (int l = 0; l < sizeof(ro)/sizeof(ro[0]); l++){
                
                    for (int p = 0; p < sizeof(num_iteraciones)/sizeof(num_iteraciones[0]); p++){
                
                        for (int q = 0; q < sizeof(probabilidad_seleccion)/sizeof(probabilidad_seleccion[0]); q++){
                            //obtener el tiempo de ejecucion del algoritmo
                            t0=clock();
                            vector<int> solucion=hormiga(distancias,num_nodes,alfa[i],beta[j],num_hormigas[k],ro[l],num_iteraciones[p],num_iteraciones[q]);
                            t1=clock();

                            //obtener y guardar los resultados
                            float valorsolucion=valor_solucion(solucion,distancias);
                            cout<<endl;cout<<"Tiempo: "<<(double(t1-t0)/CLOCKS_PER_SEC)<<" Valor de la solucion: "<<valorsolucion;
                            ficheroSalida <<(double(t1-t0)/CLOCKS_PER_SEC)<<","<<valorsolucion<<endl; 
                            cout<<endl;cout<<endl;
                        }
                    }
                }
            }
        }
    }

    ficheroSalida.close();
	return 0;
}

