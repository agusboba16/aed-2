/*
 *
 * ejercicio_1_19.cpp
 * Detección de ciclos en un grafo no dirigido usando Union-Find
 *
 */

#include <iostream>

using namespace std;

struct Arista{
    int origen;
    int destino;
    int peso; 
};

class Grafo {
	private:
		int v; 
		int a;
		int na;
		Arista* aristas;
		int Find(int* padre, int i);
		void Union(int* padre, int x, int y);
	public:
		Grafo(int, int);
		~Grafo();
		void AgregarArista(int,int,int);
		void Mostrar();
		bool TieneCiclos();	
};


Grafo::Grafo(int v, int a){
	this->v = v;
	this->a = a;
	this->na = 0;
	this->aristas = new Arista[a];
}

Grafo::~Grafo(){
	delete[] aristas;
}

void Grafo::AgregarArista(int origen, int destino, int peso){
	aristas[na].origen = origen;
	aristas[na].destino = destino;
	aristas[na].peso = peso;
	na++;
}

void Grafo::Mostrar(){
	cout << "Lista de Aristas" << endl;
	cout << "Origen\tDestino\tPeso" << endl;
	for (int i = 0; i < na; i++){
		cout << aristas[i].origen << "\t";
		cout << aristas[i].destino << "\t";
		cout << aristas[i].peso << "\n";
	}
	cout<<endl;		
}

int Grafo::Find(int* padre, int i){
	if (padre[i] == -1)
		return i;
	return Find (padre, padre[i]);
}

void Grafo::Union(int* padre, int x, int y){
	int conjuntox = Find(padre, x);
	int conjuntoy = Find(padre, y);
	padre[conjuntox] = conjuntoy;
}

bool Grafo::TieneCiclos(){
	int* padre = new int[v];
	for (int i = 0; i < v; i++){
		padre[i] = -1;
	}
	for (int i = 0; i < a; i++){
		int x = Find(padre, aristas[i].origen);
		int y = Find(padre, aristas[i].destino);
		
		
		if (x == y)
			return true;
		Union(padre, x, y);
	}

	return false;

}


int main()
{
	Grafo g(5,8);
	g.AgregarArista(0,1,1);
	g.AgregarArista(0,2,4);
	g.AgregarArista(1,2,3);  
	g.AgregarArista(1,3,2);
	g.AgregarArista(1,4,2);
	g.AgregarArista(3,2,5);
	g.AgregarArista(3,1,1);
	g.AgregarArista(4,3,3);

	g.Mostrar();
	
	if (g.TieneCiclos()){
		cout << "El grafo tiene ciclos" << endl;
	} else{
		cout << "El grafo NO tiene ciclos" << endl;
	}
	
	
	Grafo h(6,5);
	h.AgregarArista(0,1,1);
	h.AgregarArista(1,3,4);
	h.AgregarArista(3,2,3);  
	h.AgregarArista(3,4,2);
	h.AgregarArista(4,5,2);

    	
	h.Mostrar();
	
	if (h.TieneCiclos()){
		cout << "El grafo tiene ciclos" << endl;
	} else{
		cout << "El grafo NO tiene ciclos" << endl;
	}

	
	return 0;
}
