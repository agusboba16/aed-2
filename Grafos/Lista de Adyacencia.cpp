#include <iostream>
using namespace std;

struct nodo{
	int destino;
	nodo* siguiente;
};

struct Lista{
	nodo* inicio;
};

class Grafo{
	private:
		int v;
		Lista* l;
	public:
		Grafo(int);
//		~Grafo();
		void AgregarArista(int,int);
		void Mostrar();
};

Grafo::Grafo(int v){
    this->v = v;
    l = new Lista[v];
    for(int i=0; i<v; i++){
    	l[i].inicio = NULL;
	}
}

void Grafo::AgregarArista(int origen ,int destino){
	nodo* n = new nodo;
	n->destino = destino;
	n->siguiente = l[origen].inicio;
	l[origen].inicio = n;
}

void Grafo::Mostrar(){
	for(int i = 0; i<v; i++){
		nodo* n = l[i].inicio;
		cout<<i<<"->";
		while(n!=NULL){
			cout<<n->destino<<"->";
			n = n->siguiente;
		}
		cout<<"->"<<endl;
	}
}

int main(){
	Grafo g1(5);
	g1.AgregarArista(1,2);
	g1.AgregarArista(3,1);
	g1.AgregarArista(2,2);
	g1.AgregarArista(1,1);
	g1.AgregarArista(2,1);
	g1.Mostrar();
}
