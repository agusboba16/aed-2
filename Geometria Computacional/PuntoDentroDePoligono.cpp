#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

struct punto;
struct segmento;
int orientacion(punto p1, punto p2, punto p3);
int distancia(punto p1, punto p2);

struct punto
{
    int x, y;
};

int distancia(punto p1, punto p2)
{
    return ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));
}

struct segmento
{
    punto p1, p2;
};

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

bool Dentro_de_Poligono(punto p1, vector<punto> poligono)
{
    punto infinito = {9999, p1.y};
    segmento linea = {{p1}, {infinito}};
    int contador = 0;
    for (int i = 0; i < poligono.size() - 1; i++)
    {
        segmento segmentoActual = {{poligono[i]}, {poligono[i + 1]}};
        if (seIntersectan(segmentoActual, linea))
        {
            contador++;
        }
    }
    return contador % 2 != 0;
}

int main()
{
    vector<punto> poligono = {{1, 2}, {5, 2}, {3, 1}, {4, 4}, {2, 3}};
    for (int i = 0; i < poligono.size(); i++)
    {
        cout << "Punto " << i << ": "<< "{" << poligono[i].x << "," << poligono[i].y << "}" << endl;
    }
    cout << Dentro_de_Poligono({3, 3}, poligono) << endl;
    cout << Dentro_de_Poligono({4, 3}, poligono) << endl;

    return 0;
}
