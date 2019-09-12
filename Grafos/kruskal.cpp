#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Arista{
	int origen;
	int destino;
	int peso;
	bool operator < (const Arista& aristas) const{
		return(peso < aristas.peso);
	}
};

class Grafo{
      private:
        	int v;
        	int a;
       		int na;
        	Arista* aristas;
			int Find(int* padre, int i);
			void Union(int* padre, int x, int y); 
      public:
            Grafo(int,int);
            ~Grafo();
            void AgregarArista(int,int,int);
            void Kruskal();
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
void Grafo::AgregarArista(int origen, int destino,int peso){
	if (origen >= 0 && destino >= 0 && origen < v && destino < v){
		aristas[na].origen = origen;
		aristas[na].destino = destino;
		aristas[na].peso = peso;
		na++;
		
	}	
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

void Grafo::Kruskal(){
	int suma = 0;
	sort(aristas,(aristas+na));
	cout << "Origen\tDestino\tPeso" << endl;
	Arista* mst = new Arista[v-1];
	int* padre = new int[a];
	int imst=0;
	for (int i = 0; i < v; i++){
		padre[i] = -1;
	}	
	for(int i=0; i<a; i++){
		if(Find(padre,aristas[i].origen) != Find(padre,aristas[i].destino)){
			Union(padre,Find(padre,aristas[i].origen),Find(padre,aristas[i].destino));
			mst[imst] = aristas[i];
				cout << mst[imst].origen << "\t";
				cout << mst[imst].destino << "\t";
				cout << mst[imst].peso << "\n";
				suma += aristas[i].peso;
			imst++;	
		}
	}
	cout<<"Suma de pesos mst: "<<suma<<endl;
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

int main(){
	
Grafo g1(9,14);

g1.AgregarArista(0,1,4);
g1.AgregarArista(0,7,8);
g1.AgregarArista(1,2,8);
g1.AgregarArista(1,7,11);
g1.AgregarArista(2,8,2);
g1.AgregarArista(2,3,7);
g1.AgregarArista(5,2,4);
g1.AgregarArista(5,3,14);
g1.AgregarArista(3,4,9);
g1.AgregarArista(5,4,10);
g1.AgregarArista(6,5,2);
g1.AgregarArista(6,8,6);
g1.AgregarArista(7,6,1);
g1.AgregarArista(7,8,7);
g1.Mostrar();
cout<<""<<endl;
g1.Kruskal();
//g1.Mostrar();


system("pause");

return 0;
}

