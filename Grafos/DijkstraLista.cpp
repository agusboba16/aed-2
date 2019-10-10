#include <iostream>
#include <string.h>
using namespace std;

struct Dijkstra{
    int dist;
    int padre; 
    bool spt;
};

struct NodoListaAdyacencia{
    int haciaV;
    int dist;
    NodoListaAdyacencia* sig;
};

struct ListaAdyacencia{
    NodoListaAdyacencia* inicio;
};

class Grafo{
    private:
        int v;
        ListaAdyacencia* l;
        void Mostrar(NodoListaAdyacencia*);
        void Eliminar(NodoListaAdyacencia*); 
    public:
        Grafo(int);
        ~Grafo();
        void agregarArista(int, int, int);
        void Mostrar();
        void EjecutarDijkstra(int); 
        void MostrarDijkstra(Dijkstra*);   
};

int seleccionarMenor(Dijkstra *n){
    int menor=50000;
    int x;
    for(int i=0; i < 9 ; i++){
        if(n[i].dist < menor && n[i].spt==0) {
            menor= n[i].dist;
            x=i;
            }
    }

    return x;
};

Grafo::Grafo(int v){
    this->v=v;
    l= new ListaAdyacencia[v];
    for(int i=0; i<v; i++){
        l[i].inicio=NULL;
    }
};

void Grafo::Eliminar(NodoListaAdyacencia* n){
    if(n) Eliminar(n->sig);
    delete[] n; 
}

Grafo::~Grafo(){
    for(int i=0; i<v; i++){
        Eliminar(l[i].inicio);
    }
    delete[] l;
};

void Grafo::agregarArista(int o, int d, int dist){
    NodoListaAdyacencia* aux = new NodoListaAdyacencia;
    aux->haciaV=d;
    aux->dist=dist;
    aux->sig=l[o].inicio;
    l[o].inicio = aux;
    NodoListaAdyacencia* aux2 = new NodoListaAdyacencia;
    aux2->haciaV=o;
    aux2->dist=dist;
    aux2->sig=l[d].inicio;
    l[d].inicio = aux2;
    
};

void Grafo::Mostrar(){
    for(int i = 0; i < this->v ; i++){
        cout << "Nodo " << i << " conexiones con: ";
        Mostrar(l[i].inicio);
        cout << " " << endl; 
    }
}

void Grafo::Mostrar(NodoListaAdyacencia* n){
    if(n) {
        cout << n->haciaV << " ";
        Mostrar(n->sig);
    }    
};

void Grafo::EjecutarDijkstra(int origen){
    Dijkstra array[9];
    int n;
    NodoListaAdyacencia* aux;
    for(int i=0; i<9 ; i++){
        array[i].dist=50000;
        array[i].padre=-2;
        array[i].spt=false;
    }
    array[origen].padre=-1;
    array[origen].dist=0;
    for(int i=0; i<9; i++){
        n=seleccionarMenor(array);
        array[n].spt=1;
        aux=l[n].inicio;
        if(!aux && array[n].padre==-1) {
            cout << "Este nodo no esta conectado . " << endl;
            i=9;
        }    
        else
        {
            while(aux){
                if(((aux->dist + array[n].dist) < (array[aux->haciaV].dist)) && (array[aux->haciaV].spt==false)){
                    array[aux->haciaV].dist=aux->dist + array[n].dist;
                    array[aux->haciaV].padre=n;
                }
                aux=aux->sig;
            }   
        }

    }
    this->MostrarDijkstra(array);
}    

void Grafo::MostrarDijkstra(Dijkstra *array){
    for(int i=0; i < 9 ; i++){
        cout << array[i].dist << " " << array[i].padre << endl;
    }
}



int main(){
    Grafo a(9);
    a.agregarArista(0,1,4);
	a.agregarArista(0,7,8);
	a.agregarArista(1,2,8);
	a.agregarArista(1,7,11);
	a.agregarArista(2,8,2);
	a.agregarArista(2,3,7);
	a.agregarArista(5,2,4);
	a.agregarArista(5,3,14);
	a.agregarArista(3,4,9);
	a.agregarArista(5,4,10);
	a.agregarArista(6,5,2);
	a.agregarArista(6,8,6);
	a.agregarArista(7,6,1);
	a.agregarArista(7,8,7);
    a.Mostrar();
    a.EjecutarDijkstra(0);
    return 0;
}
