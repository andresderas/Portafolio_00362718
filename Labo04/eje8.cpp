//Tarea 6 y 9
#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};
//Funcion que crea nodo con el dato enviado desde la funcion toBinary
nodo *crearNodo(int dato){
	nodo *nuevo=new nodo;
	nuevo->dato=dato;
	nuevo->sig=NULL;
	return nuevo;
}
//Funcion que inserta el nodo creado en la lista
void insertar(nodo *&pInicio, nodo *&nuevo){
	if(pInicio==NULL){
		pInicio=nuevo;
	}else{
		insertar(pInicio->sig,nuevo);
	}
}
//Funcion que muestra el nodo
void mostrar(nodo *pInicio){
	if(pInicio!=NULL){
		cout<<pInicio->dato<<" ";
		mostrar(pInicio->sig);
	}
}
//Funcion que convierte numero a binario y lo pasa al nodo
void toBinary(int x, nodo *&pInicio){
	nodo*aux=NULL;
	if(x==0){
		return;
	}else{
		toBinary(x/2,pInicio);
		if(x%2==0){
			aux=crearNodo(0);
			insertar(pInicio,aux);
		}else{
			aux=crearNodo(1);
			insertar(pInicio,aux);
		}
	}
}
int main (void){
	nodo *pInicio=NULL;
	int numero;
	
	cout<<"Ingrese un numero base 10: ";
	cin>>numero;
	toBinary(numero,pInicio);
	cout<<"El numero ingresado en binario es: ";
	mostrar(pInicio);
	
	return 0;
}

