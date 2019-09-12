#include <iostream>
using namespace std;

struct numeroimag{
	double real;
	double img;
}complejo1,complejo2,respuesta;

void multicomplx();
int main(void){
	
	cout<<"Ingrese el multiplicando."<<endl;
	cout<<"Parte real: ";
	cin>>complejo1.real;
	cout<<"Parte imaginaria: ";
	cin>>complejo1.img;
	cout<<endl;
	
	cout<<"Ingrese el multiplicador."<<endl;
	cout<<"Parte real: ";
	cin>>complejo2.real;
	cout<<"Parte imaginaria: ";
	cin>>complejo2.img;
	
	multicomplx();
	
	return 0;
}

void multicomplx(){
	respuesta.real=((complejo1.real*complejo2.real)-(complejo1.img*complejo2.img));
	respuesta.img=((complejo1.real*complejo2.img)+(complejo1.img*complejo2.real));
	
	cout<<endl<<"El resultado de la multiplicacion de los numeros complejos es: ";
	cout<<"("<<respuesta.real<<","<<respuesta.img<<")";
}
