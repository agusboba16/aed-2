#include <iostream>
using namespace std;

const int M = 4;
const int N = 5;

void sumarArray(int **a,int N, int M){
int s = 0;
for(int i = 0; i<N; i++){
    for(int j = 0; j<M; j++){
    s+=a[i][j];
}
}
cout<<endl;
cout<<"Suma total: "<<s;
}
int main(){
    //crear
int **a = new int*[N];
for(int i = 0; i<N; i++){
        a[i] = new int [M];
}
//asignar 
for(int i = 0; i<N; i++){
    for(int j = 0; j<M; j++){
    a[i][j] = 1;
    }
}
//imprimir
for(int i = 0; i<N; i++){
    for(int j = 0; j<M; j++){
    cout<<a[i][j];
    }
    cout<<endl;
}
sumarArray(a,N,M);  
    cout<<endl;  
system("pause");

for(int i = 0; i<N; i++){
delete[] a[i];
    }

    return 0;
}
