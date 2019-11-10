#include <iostream>
#include <stdlib.h>
using namespace std;
struct punto
{
    int x;
    int y;
};

struct segmento
{
    punto p1;
    punto p2;
};

int orientacion(punto p1, punto p2, punto p3)
{
    int resultado = 0;

    resultado = ((p2.y - p1.y) * (p3.x - p2.x)) - ((p3.y - p2.y) * (p2.x - p1.x));
    if (resultado == 0)
    {
        return 0; //colineares
    }
    else if (resultado > 0)
    {
        return 1; //horario
    }
    else if (resultado < 0)
    {
        return -1; //antihorario
    }
}

bool estaEnsegmento(segmento s1, punto p3)
{
    int maxX = max(s1.p1.x, s1.p2.x);
    int maxY = max(s1.p1.y, s1.p2.y);
    int minX = min(s1.p1.x, s1.p2.x);
    int minY = min(s1.p1.y, s1.p2.y);

    if (p3.x <= maxX && p3.x >= minX && p3.y <= maxY && p3.y >= minY)
        return true;
    return false;
}

bool seintersectan(segmento s1, segmento s2)
{
    int o1 = orientacion(s1.p1, s1.p2, s2.p1);
    int o2 = orientacion(s1.p1, s1.p2, s2.p2);
    int o3 = orientacion(s2.p1, s2.p2, s1.p1);
    int o4 = orientacion(s2.p1, s2.p2, s1.p2);

    if ((o1 != o2) && (o3 != o4))
        return true;

    if (o1 == 0 && estaEnsegmento(s1, s2.p1))
        return true;
    if (o2 == 0 && estaEnsegmento(s1, s2.p2))
        return true;
    if (o3 == 0 && estaEnsegmento(s2, s1.p1))
        return true;
    if (o4 == 0 && estaEnsegmento(s2, s1.p2))
        return true;
    return false;
}

int main()
{
    punto p1 = {1, 2};
    punto p2 = {3, 2};
    punto p3 = {3, 3};
    punto p4 = {1, 1};
    punto p5 = {2, 2};
    punto p6 = {3, 3};
    punto p7 = {1, 2};
    punto p8 = {3, 1};
    punto p9 = {4, 0};
    cout << "Orientacion: " << orientacion(p1, p2, p3) << endl;
    cout << "Orientacion: " << orientacion(p4, p5, p6) << endl;
    cout << "Orientacion: " << orientacion(p7, p8, p9) << endl;
    segmento s1 = {{1, 1}, {3, 2}};
    segmento s2 = {{3, 1}, {1, 3}};
    string resultado;
    resultado = (seintersectan(s1, s2)) ? "Se intersectan":"No se intersectan";
    cout << "s1 y s2 "<< resultado << endl;
    
    return 0;
}