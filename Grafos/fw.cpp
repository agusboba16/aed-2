#include <iostream>
#include <climits>

using namespace std;

const int INFINITO = INT_MAX;

class Grafo {
private:
    int v;
    int **a;
    int **sp; // Matriz de caminos mínimos
    // void FloydWarshall();

public:
    Grafo(int);

    ~Grafo();

    void AgregarArista(int, int, int);

    void Mostrar();

    void CalcularFloydWarshall();

    void MostrarFloydWarshall();
};

Grafo::Grafo(int v) {
    this->v = v;

    this->a = new int *[v];
    for (int i = 0; i < v; i++) {
        a[i] = new int[v];
        for (int j = 0; j < v; j++) {
            a[i][j] = 0;
        }
    }

    this->sp = new int *[v];
    for (int i = 0; i < v; i++) {
        sp[i] = new int[v];
        for (int j = 0; j < v; j++) {
            sp[i][j] = 0;
        }
    }
}

Grafo::~Grafo() {
    for (int i = 0; i < v; i++) {
        delete[] a[i];
        delete[] sp[i];
    }
    delete[] a;
    delete[]sp;
}

void Grafo::AgregarArista(int origen, int destino, int peso) {
    if (origen >= 0 && destino >= 0 && origen < v && destino < v) {
        a[origen][destino] = peso;
        a[destino][origen] = peso; // no dirigido
    }
}

void Grafo::Mostrar() {
    cout << "Matriz de Adyacencia" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void Grafo::CalcularFloydWarshall() {
    // inicializacion
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j) {
                sp[i][j] = 0;
            } else {
                if (a[i][j] != 0) {
                    sp[i][j] = a[i][j];
                } else {
                    sp[i][j] = INFINITO;
                }
            }
        }
    }

    // procesamiento
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if ((sp[i][k] == INFINITO) || (sp[k][j] == INFINITO)) {
                    continue;
                }
                int a = sp[i][k] + sp[k][j];
                if (a >= sp[i][j]) {
                    continue;
                }
                sp[i][j] = a;
            }
        }
    }
}


void Grafo::MostrarFloydWarshall() {
    cout << "Caminos Minimos" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (sp[i][j] == INFINITO)
                cout << "-" << "\t";
            else
                cout << sp[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    Grafo m(5);
    m.AgregarArista(0, 1, 4);
    m.AgregarArista(0, 2, 8);
    m.AgregarArista(1, 2, 1);
    m.AgregarArista(1, 3, 2);
    m.AgregarArista(3, 4, 7);
    m.AgregarArista(2, 4, 2);
    m.AgregarArista(3, 2, 4);

    m.Mostrar();

    m.CalcularFloydWarshall();

    m.MostrarFloydWarshall();
}