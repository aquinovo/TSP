#include "funciones.cpp"


int main() {
    int num_nodes,node;
    pair<int,int> coordenada,coordenada1,coordenada2;
    map<int, pair<int,int> > entrada;
    map< pair<int,int>, float > distancias;
 
    cin >> num_nodes;

    while(cin >> node>> coordenada.first >> coordenada.second) {
 		 entrada[node]=coordenada;
	}

	for (int i = 1; i < entrada.size(); ++i){
		for (int j = i+1; j < entrada.size()+1; ++j){
            coordenada1.first=i; coordenada1.second=j; 
            coordenada2.first=i; coordenada2.second=j; 
            distancias[coordenada1]=sqrt( pow(entrada[i].first - entrada[j].first ,2.0) + pow(entrada[i].second - entrada[j].second,2.0) );
            distancias[coordenada2]=distancias[coordenada1];
		}
	}

	

	return 0;
}

