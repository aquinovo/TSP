#include "funciones.cpp"


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
    
    hormiga(distancias,num_nodes,1,1,5,0.10,100);
	return 0;
}

