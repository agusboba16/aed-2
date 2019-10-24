#include <iostream>
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


int orientacion(punto p1, punto p2,punto p3)
{
	int resultado=0;
	
	resultado= ((p2.y-p1.y)*(p3.x-p2.x))-((p3.y-p2.y)*(p2.x-p1.x));
	if (resultado==0) return 0; //colineares
	if (resultado>0)
	{
		return 1;//horario
	}
	else
	{
		return -1;//antihorario
	}
	
	
}


bool estaEnsegmento(segmento s1, punto p3)
{    
     int maxX=max(s1.p1.x,s1.p2.x);
     int maxY=max(s1.p1.y,s1.p2.y);
     int minX=min(s1.p1.x,s1.p2.x);
     int minY=min(s1.p1.y,s1.p2.y);
     
      if(p3.x<=maxX &&  p3.x>=minX  &&  p3.y<=maxY  && p3.y>=minY) return true;
      return false;
}




bool seintersectan(segmento s1, segmento s2)
{	
	int o1=orientacion(s1.p1,s1.p2,s2.p1);
	int o2=orientacion(s1.p1,s1.p2,s2.p2);
	int o3=orientacion(s2.p1,s2.p2,s1.p1);
	int o4=orientacion(s2.p1,s2.p2,s1.p2);
	
	if((o1!=o2)&&(o3!=o4)) return true;

	
	if(o1==0 && estaEnsegmento(s1,s2.p1)) return true;
	if(o2==0 && estaEnsegmento(s1,s2.p2)) return true;
	if(o3==0 && estaEnsegmento(s2,s1.p1)) return true;
	if(o4==0 && estaEnsegmento(s2,s1.p2)) return true; 
	return false;
}





int main()
{


	segmento s1={{1,1},{10,1}};
	segmento s2={{1,2},{10,2}};
	if (seintersectan(s1,s2)==true){
		cout << "Se intersectan"<<endl;
	}
	else
	{
		cout << "No se intersectan"<<endl;
	}

//----------------------------------------------

	segmento s3={{1,1},{10,2}};
	segmento s4={{1,2},{10,1}};
	if (seintersectan(s3,s4)==true){
		cout << "Se intersectan"<<endl;
	}
	else
	{
		cout << "No se intersectan"<<endl;
	}	
//----------------------------------------------

	segmento s5={{1,1},{10,1}};
	segmento s6={{5,1},{21,1}};
	if (seintersectan(s5,s6)==true){
		cout << "Se intersectan"<<endl;
	}
	else
	{
		cout << "No se intersectan"<<endl;
	}	
	
//----------------------------------------------

	segmento s7={{1,1},{10,1}};
	segmento s8={{18,1},{21,1}};
	if (seintersectan(s7,s8)==true){
		cout << "Se intersectan"<<endl;
	}
	else
	{
		cout << "No se intersectan"<<endl;
	}	
	
	system("pause");
	return 0;
}