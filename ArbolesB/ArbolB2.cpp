/*
 *
 * ejercicio_2_01.cpp
 * Implementación de un Árbol B en memoria
 *
 */

#include <iostream>

using namespace std;

class NodoArbolB
{
private:
    int *claves;        //Arreglo de claves
    NodoArbolB **hijos; //Array de punteros a los hijos
    int t;              //Grado mínimo
    int n;              //Cantidad de claves que tiene el nodo
    bool esHoja;

public:
    NodoArbolB(int, bool);
    void Recorrer();
    NodoArbolB *Buscar(int);
    void InsertarEnNodoNoLleno(int);
    void DividirHijo(int, NodoArbolB *);
    friend class ArbolB;
};

class ArbolB
{
private:
    NodoArbolB *raiz;
    int t;

public:
    ArbolB(int);
    void Recorrer();
    NodoArbolB *Buscar(int);
    void Insertar(int);
};

// *********************************************
// Implementación de los miembros de NodoArbolB
// *********************************************

NodoArbolB::NodoArbolB(int t, bool esHoja)
{
    this->t = t;
    this->esHoja = esHoja;
    claves = new int[2 * t - 1];
    hijos = new NodoArbolB *[2 * t];
    n = 0;
}

// NodoArbolB* NodoArbolB::Buscar(int clave){
// }

// *********************************************
// Implementación de los miembros de ArbolB
// *********************************************

ArbolB::ArbolB(int t)
{
    raiz = NULL;
    this->t = t;
}

void NodoArbolB::Recorrer()
{
    if (!esHoja)
    {
        hijos[0]->Recorrer();
    }
    hijos[0]->Recorrer();
    for (int i = 0; i < n; i++)
    {
        cout << claves[i];
        if (!esHoja)
        {
            hijos[i]->Recorrer();
        }
    }
}

void ArbolB::Recorrer()
{
    if (raiz == NULL)
    {
        return;
    }
    raiz->Recorrer();
}

NodoArbolB *NodoArbolB::Buscar(int k)
{
    int i = 0;
    while (i < n && k > claves[i])
    {
        i++;
    }
    if (claves[i] == k && i < n)
    {
        return this;
    }
    if (esHoja)
    {
        return NULL;
    }
    return hijos[i]->Buscar(k);
}

NodoArbolB *ArbolB::Buscar(int k)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    return raiz->Buscar(k);
}

void ArbolB::Insertar(int k)
{
    if (raiz == NULL)
    {
        // Crea el nodo raiz
        raiz = new NodoArbolB(t, true);
        raiz->claves[0] = k;
        raiz->n = 1;
    }
    else // Si el árbol no está vacío
    {
        // Si la raiz está llena, crece en altura
        if (raiz->n == 2 * t - 1)
        {
            // Creamos la nueva raiz
            NodoArbolB *s = new NodoArbolB(t, false);

            // La raiz anterior ahora es hija de la nueva
            s->hijos[0] = raiz;

            // Dividimos la raiz anterior y movemos una clave a la nueva raiz
            s->DividirHijo(0, raiz);

            // Ahora la raiz nueva tiene dos hijos.
            //	Decidimos cual de los dos tendrá la nueva clave
            int i = 0;
            if (s->claves[0] < k)
                i++;
            s->hijos[i]->InsertarEnNodoNoLleno(k);

            // Cambiamos la raiz
            raiz = s;
        }
        else // Si la raiz no está llena, insertamos en la raiz
            raiz->InsertarEnNodoNoLleno(k);
    }
}

void NodoArbolB::InsertarEnNodoNoLleno(int k)
{
    // Inicializamos el indice con la posición del elemento más a la derecha
    int i = n - 1;

    // Si es una hoja
    if (esHoja)
    {
        // a) Encontramos la ubicación de la clave a ser insertada
        // b) Movemos las claves más grandes un lugar hacia adelante
        while (i >= 0 && claves[i] > k)
        {
            claves[i + 1] = claves[i];
            i--;
        }

        // Insertamos la nueva clave en la ubicación encontrada
        claves[i + 1] = k;
        n = n + 1;
    }
    else // Si no es una hoja
    {
        // Buscamos el hijo que tendrá la nueva clave
        while (i >= 0 && claves[i] > k)
            i--;

        // Nos fijamos si está lleno
        if (hijos[i + 1]->n == 2 * t - 1)
        {
            // Si el hijo está lleno, lo dividimos
            DividirHijo(i + 1, hijos[i + 1]);

            // Despues de dividirlo, la clave de la mitad de c[i] sube
            // y c[i] queda dividida en dos. Hay que ver cual de las dos mitades
            // va a tener la nueva clave
            if (claves[i + 1] < k)
                i++;
        }
        hijos[i + 1]->InsertarEnNodoNoLleno(k);
    }
}

// y debe estar lleno cuando llamamos a esta función
void NodoArbolB::DividirHijo(int i, NodoArbolB *y)
{
    // Crea un nuevo nodo que va a a almacenar (t-1) claves de y
    NodoArbolB *z = new NodoArbolB(y->t, y->esHoja);
    z->n = t - 1;

    // Copia las ultimas t-1 claves de y a
    for (int j = 0; j < t - 1; j++)
        z->claves[j] = y->claves[j + t];

    // Copia los ultimos t hijos de y a
    if (y->esHoja == false)
    {
        for (int j = 0; j < t; j++)
            z->hijos[j] = y->hijos[j + t];
    }

    // Reduce el número de claves en y
    y->n = t - 1;

    // Como este nodo tendrá un nuevo hijo
    // creamos espacio para ese hijo
    for (int j = n; j >= i + 1; j--)
        hijos[j + 1] = hijos[j];

    // Conectamos el nuevo hijo a este nodo
    hijos[i + 1] = z;

    // Una clave de y se mueve a este nodo. Buscamos la ubicación
    // de la nueva clave y movemos el resto de las claves hacia adelant
    for (int j = n - 1; j >= i; j--)
        claves[j + 1] = claves[j];

    // Copiamos la clave del medio de y a este nodo
    claves[i] = y->claves[t - 1];

    // Incrementamos el contador de claves del nodo
    n = n + 1;
}

int main()
{
    ArbolB t(3); //Arbol B con t = 3
    t.Insertar(10);
    t.Insertar(20);
    t.Insertar(5);
    t.Insertar(6);
    t.Insertar(12);
    t.Insertar(30);
    t.Insertar(7);
    t.Insertar(17);

    cout << "Recorrido del árbol:";
    t.Recorrer();

    int k = 6;
    (t.Buscar(k) != NULL) ? cout << "\nLa clave: " << k << " Está\n" : cout << "\nLa clave: " << k << " No Está\n";

    //   k = 15;
    // (t.Buscar(k) != NULL)? cout << "\nLa clave: " << k << " Está\n" : cout  << "\nLa clave: " << k << " No Está\n";

    return 0;
}
