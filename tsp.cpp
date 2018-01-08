#include "funciones.cpp"


int main() {
    int num_nodes,node;
    pair<int,int> coordenada,coordenada1,coordenada2;
    pair<float,float> valores;
    map<int, pair<int,int> > entrada;
    map< pair<int,int>, pair<float,float> > distancias;
 
    cin >> num_nodes;

    while(cin >> node>> coordenada.first >> coordenada.second) {
 		 entrada[node]=coordenada;
	}

	for (int i = 1; i < entrada.size(); i++){
		for (int j = i+1; j < entrada.size()+1; j++){
            coordenada1.first=i; coordenada1.second=j; 
            coordenada2.first=j; coordenada2.second=i; 
            
            valores.first= sqrt( pow(entrada[i].first - entrada[j].first ,2.0) + pow(entrada[i].second - entrada[j].second,2.0) );
            valores.second= 1/sqrt( pow(entrada[i].first - entrada[j].first ,2.0) + pow(entrada[i].second - entrada[j].second,2.0) );

            distancias[coordenada1]=valores;
            distancias[coordenada2]=valores;
            
		}	
	}

	for (int i = 1; i < 2; i++){
		for (int j = i+1; j < 10; j++){
			 coordenada1.first=i; coordenada1.second=j; 
             cout<<distancias[coordenada1].first<<" -> "<<distancias[coordenada1].second<<endl;
		}
	}	

    crear_solucion(entrada,distancias,num_nodes);


	return 0;
}

