#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Heap
{
private:
    vector<int> h;
    int Padre(int);
    int hijoIzq(int);
    int hijoDer(int);

public:
    Heap();
    void insertarClave(int);
    void Heapify(int);
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

Heap::Heap()
{
}

void Heap::insertarClave(int clave)
{
    int i = h.size();
    h.push_back(clave);
    while (i != 0 && h[i] < h[Padre(i)])
    {
        swap(h[i], h[Padre(i)]);
        i = Padre(i);
    }
}

void Heap::mostrar()
{
    for (vector<int>::iterator i = h.begin(); i != h.end(); ++i)
    {
        cout << (*i) << " ";
    }
    cout << endl;
}

void Heap::Heapify(int i)
{
    int raiz = i;
    int l = hijoIzq(i);
    int r = hijoDer(i);
    if (l < h.size() && h[l] < h[i])
    {
        raiz = l;
    }
    if (r < h.size() && h[r] < h[raiz])
    {
        raiz = r;
    }
    if (raiz != i)
    {
        swap(h[i], h[raiz]);
        Heapify(raiz);
    }
}

int Heap::extraerMinimo()
{
    int raiz;
    if (h.empty())
    {
        raiz = INT_MIN;
    }
    else if (h.size() == 1)
    {
        raiz = h.front();
        h.pop_back();
    }
    else
    {
        raiz = h.front();
        h[0] = h.back();
        h.pop_back();
        Heapify(0);
    }
    return raiz;
}
int main()
{
    Heap h1;
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
    cout << endl;
    cout << "El minimo es:" << h1.extraerMinimo()<<endl;
    h1.mostrar();
    cout << "El minimo es:" << h1.extraerMinimo()<<endl;
    h1.mostrar();
    cout << "El minimo es:" << h1.extraerMinimo()<<endl;
    h1.mostrar();
    cout << "El minimo es:" << h1.extraerMinimo()<<endl;
    h1.mostrar();
    cout << "El minimo es:" << h1.extraerMinimo()<<endl;
    h1.mostrar();
    cout << "El minimo es:" << h1.extraerMinimo()<<endl;
    h1.mostrar();
    cout << "El minimo es:" << h1.extraerMinimo()<<endl;
    h1.mostrar();

    return 0;
}