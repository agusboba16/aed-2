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
		void RecorrerProfundidad(int,bool*);
	public:
		Grafo(int);
//		~Grafo();
		void AgregarArista(int,int);
		void Mostrar();
		void RecorrerAmplitud();
		void RecorrerProfundidad();
};

Grafo::Grafo(int v){
    this->v = v;
    l = new Lista[v];
    for(int i=0; i<v; i++){
    	l[i].inicio = NULL;
	}
}
/*
Grafo::~Grafo(){
	for(int i=0; i<v; i++){
		nodo* n = l[i].inicio;
		while(n!=NULL){
			nodo* aux = n;
			n = aux->siguiente;
			delete aux;
		}
	}
}*/

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

void Grafo::RecorrerAmplitud(){
	cout<<"En amplitud: ";
	int v_actual = 0;
	bool* visitado = new bool[v];
	for(int i = 0; i<v; i++){
		visitado[i] = false;
	}
	queue<int>c;
	c.push(v_actual);
	visitado[v_actual] = true;
	while(!c.empty()){
		v_actual = c.front();
			cout<<v_actual<<" ";
			c.pop();
		nodo* n = l[v_actual].inicio;
		while(n!=NULL){
			if(!visitado[n->destino]){
				visitado[n->destino] = true;
				c.push(n->destino);
			}
			n = n->siguiente;
		}
	}
}


void Grafo::RecorrerProfundidad(int v,bool* visitado){
	cout<< v << " ";
	visitado[v] = true;
	nodo* n = l[v].inicio;
	while(n!=NULL){
		if(!visitado[n->destino]){
			RecorrerProfundidad((n->destino),visitado);
		}
		n = n->siguiente;
	}
}

void Grafo::RecorrerProfundidad(){
	bool* visitado = new bool[v];
	for(int i=0; i<v; i++){
		visitado[i] = false;
	}
	int v_inicial = 0;
	RecorrerProfundidad(v_inicial, visitado);
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
	g1.RecorrerAmplitud();
	cout<<endl;
	cout<<"En profundidad: ";
	g1.RecorrerProfundidad();

}
