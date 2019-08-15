#include <iostream>
using namespace std;
const int n  = 5;
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
}        
void Grafo::Mostrar(){
        for(int i = 0; i<v; i++){
    for(int j = 0; j<v; j++){
    cout<<a[i][j];
    }
    cout<<endl;
}
}            
int main(){
Grafo g1(5);
g1.AgregarArista(3,4);
g1.AgregarArista(3,3);
g1.AgregarArista(3,1);
g1.Mostrar();

system("pause");
    return 0;
}
