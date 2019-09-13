#include <iostream>
#include <climits>
using namespace std;
int INFINITO = INT_MAX;

class Grafo{
      private:
              int v;
              int **a;
      public:
             Grafo(int);
             ~Grafo();
             void AgregarArista(int,int,int);
             void Mostrar();
             int Mindistancia(int[],bool[]);
             void mostrarPrim(int[],int[]);
             void Prim(int);
      };

struct Arista{
	int padre;
	int peso;
	bool mst;
};      
Grafo::Grafo(int v){
      this->v = v;
      this->a = new int* [v];
        for(int i = 0; i<v; i++){
        a[i] = new int [v];
        for(int j = 0; j<v; j++){
                a[i][j] = 0;
                }
       		}
        }
        
       Grafo::~Grafo(){
       for(int i = 0; i<v; i++){
       delete[] a[i];
    }
}
void Grafo::AgregarArista(int origen, int destino,int dist){
	if (origen >= 0 && destino >= 0 && origen < v && destino < v){
		a[origen][destino] = dist;
		a[destino][origen] = dist;
	}	
}       

void Grafo::Mostrar(){
        for(int i = 0; i<v; i++){
    		for(int j = 0; j<v; j++){
    			cout<<a[i][j]<<"\t";
    		}
    	cout<<endl;
	}
}     

int Grafo::Mindistancia(int dist[],bool mst[]){
	int min = INFINITO;
	int indice = -1;
	for(int i =0; i<v; i++){
		if(mst[i] == false && dist[i] <= min){
			min = dist[i];
			indice = i;
		}
	}
	return indice;
}

void Grafo::Prim(int origen){
	bool* mst = new bool [v];
	int* padre = new int [v];
	int* dist = new int [v];
	for(int i=0; i<v; i++){
		dist[i] = INFINITO;
		mst[i] = false;
	}
	padre[origen] = -1;
	dist[origen] = 0;
			for(int i=0; i<v-1; i++){
			int m = Mindistancia(dist,mst);
			mst[m] = true;
			for(int j = 0; j<v; j++){
				if(a[m][j] && mst[j]==false && a[m][j]< dist[j]){
					padre[j]= m;
					dist[j] = a[m][j];
			}
		}
	}
	mostrarPrim(padre,dist);
}

void Grafo::mostrarPrim(int padre[], int dist[]){
	for(int i = 0; i<v;i++){
		cout<<"["<<i<<"]"<<": "<<padre[i]<<" - "<<dist[i]<<endl;
	}
}

int main(){
	
Grafo g1(9);

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
cout<<endl;
g1.Prim(0);
system("pause");

return 0;
}

