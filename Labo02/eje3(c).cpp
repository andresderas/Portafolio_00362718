#include <iostream>
#include <cmath>
using namespace std;

long double functi(long double n,long double suma, float numero){
	if(n==0){
		return (suma);
      }else{
	  	return suma+=((((pow(-1, n+1))/(n))*pow(numero, n)) + functi(n-1, suma, numero));
	  }
}

int main(void){
	float numero = 0;
	//Numero tendiedno a infinito
	long double inicial=1800;
	cout<<"Ingrese el numero x entre 0 y 1 del que quiere saber el logaritmo + 1 (x+1): ";
	cin>>numero;
	if(numero<=-1 || numero>1){
		cout<<"numero ingresado no valido";
		return 0;
	}
	cout<<"El logaritmo natural del numero ingresado es: "<<functi(inicial, 0, numero);
	return 0;
}	
