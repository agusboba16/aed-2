#include <iostream>
#include <queue>
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
		~Grafo();
		void AgregarArista(int,int);
		void Mostrar();
		void Kahn();

};

Grafo::Grafo(int v){
    this->v = v;
    l = new Lista[v];
    for(int i=0; i<v; i++){
    	l[i].inicio = NULL;
	}
}

Grafo::~Grafo(){
	for(int i=0; i<v; i++){
		nodo* n = l[i].inicio;
		while(n!=NULL){
			nodo* aux = n;
			n = aux->siguiente;
			delete aux;
		}
	}
	delete[] l;
}

void Grafo::AgregarArista(int origen ,int destino){
	nodo* n = new nodo;
	n->destino = destino;
	n->siguiente = l[origen].inicio;
	l[origen].inicio = n;
	
	/*si es no dirigido
	nodo* n = new nodo;
	n->destino = origen;
	n->siguiente = l[destino].inicio;
	l[origen].inicio = n;*/	
}

void Grafo::Mostrar(){
	for(int i = 0; i<v; i++){
		int g = 1;
		nodo* n = l[i].inicio;
		cout<<i<<"->";
		while(n!=NULL){
			cout<<n->destino<<"->";
			cout<<"grado: "<<g;
			g = g+1;
			n = n->siguiente;
		}
		cout<<"->"<<endl;
	}
}

void Grafo::Kahn(){
	bool* visitado = new bool[v];
	for(int i=0;i<v;i++){
		visitado[i] = false;
	}
	
}
int main(){
	Grafo g1(6);
	g1.AgregarArista(0,1);
	g1.AgregarArista(0,2);
	g1.AgregarArista(1,3);
	g1.AgregarArista(2,3);
	g1.AgregarArista(2,4);
	g1.AgregarArista(4,5);
	g1.AgregarArista(5,3);
	g1.Mostrar();
	
}
