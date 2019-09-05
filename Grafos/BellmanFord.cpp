#include <iostream>
#include <climits>

using namespace std;

const int INFINITO = INT_MAX;

struct Arista{
	int origen,destino,peso;
		
};
struct Lista{
	Arista* inicio;
};
class Grafo {
private:
    int v;
    int e;
    int ne;
	Arista **a;
public:
    Grafo(int,int);

  //  ~Grafo();

    void AgregarArista(int, int, int);

    void Mostrar();
    
    void BellmanFord(int);

};

Grafo::Grafo(int v,int e) {
	ne = 0;
    this->v = v;
	this->e = e;
    this->a = new Arista *[e];
    for (int i = 0; i < v; i++) {
        a[i] = NULL;
    }
}
/*Grafo::~Grafo() {
    delete[] a;
}*/

void Grafo::AgregarArista(int origen, int destino, int peso) {
	Arista* nuevaArista = new Arista;
	
    if (origen >= 0 && destino >= 0 && origen < v && destino < v) {
    	nuevaArista->origen = origen;
		nuevaArista->destino = destino;
    	nuevaArista->peso = peso;
    	a[ne] = nuevaArista;
    	ne++;
        //a[destino][origen] = peso; // no dirigido        
    }
}



void Grafo::BellmanFord(int origen){
	int* distancia = new int[v];
	int* padre = new int[v];
	for(int i=0; i<v; i++){
		distancia[i] = INFINITO;
		padre[i] = -1;
	}
	distancia[origen] = 0;
	padre[origen] = -1;
	for(int i=0; i<v-1; i++){
		for(int j=0; j<e; j++){
			if(distancia[a[j]->origen] != INFINITO && distancia[a[j]->origen] + a[j]->peso < distancia[a[j]->destino]){
				distancia[a[j]->destino] = distancia[a[j]->origen] + a[j]->peso;
				
			}		
		}
	
	}
	cout<<"Lista distancias: ";
	for(int i=0; i<v; i++){
			cout<<distancia[i]<<" ";
		}
		cout<<endl;
	cout<<"Lista padres: ";
	for(int i=0; i<v; i++){
			cout<<padre[i]<<" ";
		}
		cout<<endl;	
}


void Grafo::Mostrar(){
	while(a){
		for(ne=0;ne<10;ne++){
			cout<<a[ne]->origen<<" "<<a[ne]->destino<<" "<<endl;		
		}
	}
	
}

int main() {
    Grafo m(5,8);
    m.AgregarArista(0, 1, -1);
    m.AgregarArista(0, 2, 4);
    m.AgregarArista(1, 2, 3);
    m.AgregarArista(1, 3, 2);
    m.AgregarArista(1, 4, 2);
    m.AgregarArista(3, 2, 5);
    m.AgregarArista(3, 1, 1);
    m.AgregarArista(4, 3, -3);
    
	//m.Mostrar();
	m.BellmanFord(0);
}
