#include<iostream>
using namespace std;

void Busqueda(string cadena,string patron){
    int n = cadena.size();
    int m = patron.size();
    int z = n-m;
    for (int i = 0; i < z+1; i++)
    {
        int j = 0;
        while (j<m+1)
        {
            if(j==m-1){
                cout<<"La palabra " << patron <<" se encontro el patron que empieza en la posicion "<<i<< "y termina en la posicion "<<i+m-1<<endl;
            }
            if(cadena[i+j] != patron[j]){
                j = m;
            }
            j++;
        }
        
    }
    
}


int main(){
    Busqueda("llamollamo","llamo");
    return 0;
}