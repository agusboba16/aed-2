#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct punto;
struct segmento;
int orientacion(punto p1, punto p2, punto p3);
int distancia(punto p1, punto p2);
int px, py;

struct punto {
    int x, y;
    bool operator < (const punto &p1) {
        int o = orientacion({px,py}, {x,y}, p1);
        if (o == 0) { //Colineal
            return distancia({px,py}, {x,y}) < distancia({px,py}, {p1.x,p1.y});
        }
        else return o == -1; //Antihorario
    }
};

int distancia(punto p1, punto p2){
    return ((p1.x-p2.x) * (p1.x-p2.x))  +  ((p1.y-p2.y) * (p1.y-p2.y));
}

struct segmento {
    punto p1, p2;
};

int orientacion(punto p1, punto p2, punto p3) {
    int resultado = (p2.y-p1.y)*(p3.x-p2.x)-(p3.y-p2.y)*(p2.x-p1.x);
    int delta1 = (p2.y-p1.y)*(p3.x-p2.x);
    int delta2 = (p3.y-p2.y)*(p2.x-p1.x);
    
    if (delta1 > delta2) { //Horario
        return 1;
    }
    
    if (delta1 < delta2) { //Antihorario
        return -1;
    }
    if(delta1 == delta2 ){
    return 0;    
    }
    return 0;
}

bool estaEnSegmento(segmento s1, punto p3) {
    int maxX = max(s1.p1.x, s1.p2.x);
    int maxY = max(s1.p1.y,s1.p2.y);
    int minX = min(s1.p1.x,s1.p2.x);
    int minY = min(s1.p1.y,s1.p2.y);
    
    if (p3.x<=maxX &&  p3.x>=minX  &&  p3.y<=maxY  && p3.y>=minY) return true;
    
    return false;
}

bool seIntersectan(segmento s1, segmento s2) {
    int o1 = orientacion(s1.p1, s1.p2, s2.p1);
    int o2 = orientacion(s1.p1, s1.p2, s2.p2);
    int o3 = orientacion(s2.p1, s2.p2, s1.p1);
    int o4 = orientacion(s2.p1, s2.p2, s1.p2);
    
    if (o1 != o2 && o3 != o4) return true;
    
    if (o1==0 && estaEnSegmento(s1,s2.p1)) return true;
    if (o2==0 && estaEnSegmento(s1,s2.p2)) return true;
    if (o3==0 && estaEnSegmento(s2,s1.p1)) return true;
    if (o4==0 && estaEnSegmento(s2,s1.p2)) return true;
    
    return false;
}

int crearCamino(punto *s, int tamano){
    int miny = s[0].y;
    int minindice = 0;
    for(int i=0;i<tamano;i++){
        int y= s[i].y;
        if(y < miny || (y == miny && s[i].x < s[minindice].x)){
            miny=y;
            minindice=i;
        }
    }
    swap(s[0],s[minindice]);
    px=s[0].x;
    py=s[0].y;
    sort(s+1,s+tamano);
    for(int i=0;i<tamano;i++)
        cout <<"Punto"<<i+1<<": ("<< s[i].x << "," <<s[i].y<<")"<<endl;

    return 0;
}

void noHaceFalta(punto*s, int tamano){
    crearCamino(s,tamano);
    vector<punto>eliminados;
    for (int i = 0; i < tamano; i++)
    {
        int o = orientacion(s[i],s[i+1],s[i+2]); 
        cout<<"Orientacion: "<<o<<endl;
        if(o==0){
            cout<<"entro"<<endl;
            eliminados.push_back(s[i+1]);
        }
    }
    cout<<"Los puntos que se pueden eliminar sin que el poligono cambie de forma son :"<<endl;
    for (int i = 0; i < eliminados.size(); i++)
    {
        cout<<eliminados[i].x<<" "<<eliminados[i].y<<endl;
    }
    
}

int main() {
    /*string resultado;
    
    segmento s1 = {{2,1}, {6,3}};
    segmento s2 = {{5,1}, {3,5}};
    resultado = (seIntersectan(s1, s2))? "si":"no";
    cout << "Los segmentos " << resultado << " se intersectan." << endl;
    
    segmento s3 = {{1,1}, {5,5}};
    segmento s4 = {{2,1}, {6,3}};
    resultado = (seIntersectan(s3, s4))? "si":"no";
    cout << "Los segmentos " << resultado << " se intersectan." << endl;
    
    segmento s5 = {{1,1}, {3,3}};
    segmento s6 = {{2,2}, {5,5}};
    resultado = (seIntersectan(s5, s6))? "si":"no";
    cout << "Los segmentos " << resultado << " se intersectan." << endl;*/
    //punto s[] = {{4,1}, {6,2}, {7,5}, {3,6}, {2,5},{1,4},{0,3}};
    punto s[] = {{6,2}, {4,1}, {3,6}, {7,5}, {2,5},{1,4},{0,3}};
    int tamano = sizeof(s)/sizeof(s[0]);
   crearCamino(s, tamano);
    cout<<endl;
    noHaceFalta(s,tamano);

    
    return 0;
}
