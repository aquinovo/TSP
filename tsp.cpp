#include "funciones.cpp"


int main() {
    int num_nodes,node;
    pair<int,int> coordenada;
    map<int, pair<int,int> > entrada;

    cin >> num_nodes;

    while(cin >> node>> coordenada.first >> coordenada.second) {
 		 entrada[node]=coordenada;
	}

	return 0;
}

