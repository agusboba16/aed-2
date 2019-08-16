#include <iostream>
using namespace std;
const int n = 5;
//const int v = 5;
class Grafo{
      private:
              int v;
              int **a;
      public:
             Grafo(int);
             ~Grafo();
             void AgregarArista(int,int);
             void Mostrar();
             void Warshall();
      };
      
Grafo::Grafo(int v){
      this->v = v;
      this->a = new int* [v];
        for(int i = 0; i<v; i++){
        a[i] = new int [n];
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
void Grafo::AgregarArista(int x ,int y){
    a[x][y] = 1;
    //a[y][x] = 1;
}        
void Grafo::Mostrar(){
        for(int i = 0; i<v; i++){
    for(int j = 0; j<v; j++){
    cout<<a[i][j];
    	}
    cout<<endl;
	}
}
void Grafo::Warshall(){
	for(int k = 0; k<v; k++){
		for(int i = 0; i<v; i++){
    		for(int j = 0; j<v; j++){
    			if((a[i][k] && a[k][j] == 1) || (a[i][j] == 1)){
    				a[i][j] = 1;
				}
    		}
		}
	}
}
	            
int main(){
	
Grafo g1(5);
Grafo g2(4);
g1.AgregarArista(3,4);
g1.AgregarArista(3,3);
g1.AgregarArista(3,1);
g1.Mostrar();
cout<<endl;
g2.AgregarArista(2,1);
g2.AgregarArista(3,0);
g2.AgregarArista(1,2);
g2.AgregarArista(3,2);
g2.AgregarArista(1,3);
g2.Mostrar();
g2.Warshall();
cout<<endl;
g2.Mostrar();
system("pause");

return 0;
}

