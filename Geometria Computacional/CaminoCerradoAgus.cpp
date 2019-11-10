#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

struct punto
{
    int x;
    int y;
    float angulo;
};

struct segmento
{
    punto p1, p2;
};

bool compararPuntos(punto* p1, punto* p2)
{
    return p1->angulo < p2->angulo;
}

void Mostrar(punto p1)
{
    cout << "[" << p1.x << "," << p1.y << "," << p1.angulo << "]";
}

int orientacion(punto p1, punto p2, punto p3)
{
    int resultado = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);

    if (resultado > 0)
    { //Horario
        return 1;
    }

    if (resultado < 0)
    { //Antihorario
        return -1;
    }

    return 0;
}

bool estaEnSegmento(segmento s1, punto p3)
{
    int maxX = max(s1.p1.x, s1.p2.x);
    int maxY = max(s1.p1.y, s1.p2.y);
    int minX = min(s1.p1.x, s1.p2.x);
    int minY = min(s1.p1.y, s1.p2.y);

    if (p3.x <= maxX && p3.x >= minX && p3.y <= maxY && p3.y >= minY)
        return true;

    return false;
}

bool seIntersectan(segmento s1, segmento s2)
{
    int o1 = orientacion(s1.p1, s1.p2, s2.p1);
    int o2 = orientacion(s1.p1, s1.p2, s2.p2);
    int o3 = orientacion(s2.p1, s2.p2, s1.p1);
    int o4 = orientacion(s2.p1, s2.p2, s1.p2);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && estaEnSegmento(s1, s2.p1))
        return true;
    if (o2 == 0 && estaEnSegmento(s1, s2.p2))
        return true;
    if (o3 == 0 && estaEnSegmento(s2, s1.p1))
        return true;
    if (o4 == 0 && estaEnSegmento(s2, s1.p2))
        return true;

    return false;
}

void calcularAngulo(vector<punto*> camino, int menor){
    for(int i = 0; i < camino.size(); i++){
        if(i != menor){
            if((camino[i]->x - camino[menor]->x) == 0.0 ){
                camino[i]->angulo = 90.0;
            } else {
                float deltaX = camino[i]->x - camino[menor]->x;
                float deltaY = camino[i]->y - camino[menor]->y;
                camino[i]->angulo = atan(deltaY/deltaX) + 57,29578;
            }
        }
        cout <<"El angulo theta es: "<< camino[i]->angulo<< endl;
    }
}

int crearCaminoConAngulo(vector<punto*> camino)
{
    int minY = camino[0]->y;
    int minindice = 0;
    for (int i = 0; i < camino.size(); i++)
    {
        int y = camino[i]->y;
        if (y < minY || (y == minY && camino[i]->x < camino[minindice]->x))
        {
            minY = y;
            minindice = i;
        }
    }
    calcularAngulo(camino,minindice);
    //swap(camino[0],camino[minindice]);
    sort(camino.begin(), camino.end(), compararPuntos);
    for (int i = 0; i < camino.size(); i++)
    {
        cout << "Punto " << i << ": (" << camino[i]->x << "," << camino[i]->y << ")" << endl;
    }
    return 0;
}

int main()
{
    
    vector<punto*>camino;
    punto *p1 = new punto{7,2,0.0};
    punto *p2 = new punto{6,4,0.0};
    punto *p3 = new punto{2,3,0.0};
    punto *p4 = new punto{4,5,0.0};
    punto *p5 = new punto{4,1,0.0};

    camino.push_back(p1);
    camino.push_back(p2);
    camino.push_back(p3);
    camino.push_back(p4);
    camino.push_back(p5);

    crearCaminoConAngulo(camino);
    return 0;
}
/* sort(camino.begin(),(camino.end()+camino.size()),compararPuntos);
    cout << endl;
    cout << "Despues de ordenar: " << endl;
    for (int i = 0; i < camino.size(); i++)
    {
        Mostrar(camino[i]);
    }*/