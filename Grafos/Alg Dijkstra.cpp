//algoritmo de dijkstra

#include <iostream>
#include <climits>
using namespace std;


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
             void Dijkstra();
             void MostrarDijkstra(int[],int[]);
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
	}	
}       

void Grafo::Mostrar(){
        for(int i = 0; i<v; i++){
    		for(int j = 0; j<v; j++){
    			cout<<a[i][j]<<" ";
    		}
    	cout<<endl;
	}
}     

int Grafo::Mindistancia(int d[],bool spt[]){
	int min = INT_MAX;
	int indice = -1;
	for(int i =0; i<v; i++){
		if(spt[i] == false && d[i] <= min){
			min = d[i];
			indice = i;
		}
	}
	return indice;
}
void Grafo::Dijkstra(){
	int origen = 0;
	bool* spt = new bool [v];
	int* padre = new int [v];
	int* d = new int [v];

	for(int i=0; i<v; i++){
		spt[i] = false;
		d[i] = INT_MAX;
		padre[i] = -1;
	}
	d[origen] = 0;
	//seleccionamos menor distancia e incorporamos al spt
	for(int i=0; i<v; i++){
	int m = Mindistancia(d,spt);
	spt[m] = true; // ponemos en true array spt
	cout<<"Menor: "<<m<<"\n";
	for(int j = 0; j<v; j++){	
		if(!spt[j] && a[m][j] && d[m] != INT_MAX && d[m] + a[m][j] < d[j]){
			d[j] = d[m]+a[m][j];
			padre[j] = m;
			}
		}
	}
	MostrarDijkstra(d, padre);
}
void Grafo::MostrarDijkstra(int d[],int padre[]){
	cout<<"Indice"<<"Distancia"<<"Padre"<<endl;
	for(int i = 0; i<v; i++){
		cout<<i<<"|"<<d[i]<<" | "<< padre[i];
		cout<<"\n";	
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
g1.Dijkstra();
system("pause");

return 0;
}

