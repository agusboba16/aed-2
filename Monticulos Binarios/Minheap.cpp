#include <iostream>
#include <algorithm>

using namespace std;

class Heap
{
private:
    int *h;
    int cap;
    int n; //posicion del ultimo elemento
    int Padre(int);
    int hijoIzq(int);
    int hijoDer(int);

public:
    Heap(int);
    void insertarClave(int);
    int obtenerMinimo();
    int extraerMinimo();
    void mostrar();
};

int Heap::hijoIzq(int i)
{
    return (i * 2) + 1;
}

int Heap::hijoDer(int i)
{
    return (i * 2) + 2;
}

int Heap::Padre(int i)
{
    return (i - 1) / 2;
}

Heap::Heap(int cap)
{
    this->cap = cap;
    h = new int[cap];
    this->n = 0;
}

void Heap::insertarClave(int clave)
{
    n++;
    int i = n - 1;
    h[i] = clave;
    while (i != 0 && h[i] < h[Padre(i)])
    {
        swap(h[i], h[Padre(i)]);
        i = Padre(i);
    }
}

void Heap::mostrar()
{
    for (int i = 0; i < n; i++)
    {
        cout << h[i]<<"\t";
    }
    cout<<endl;
}
int main()
{
    Heap h1(100);
    h1.insertarClave(20);
    h1.mostrar();
    h1.insertarClave(10);
    h1.mostrar();
    h1.insertarClave(1);
    h1.mostrar();
    h1.insertarClave(40);
    h1.mostrar();
    h1.insertarClave(21);
    h1.mostrar();
    h1.insertarClave(33);
    h1.mostrar();
    h1.insertarClave(50);
    h1.mostrar();
    return 0;
}