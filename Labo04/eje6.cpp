#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};
//Funcion que ingresa dato a la lista
void insertarnodo(int dato,nodo *&pInicio){
	nodo *nuevo;
	nuevo = new nodo;
	nuevo->dato=dato;
	nuevo->sig=pInicio;
	pInicio=nuevo;
}
//Funcion que muestra la lista ingresada
void mostrarlista(nodo *&pInicio){
	nodo *p=pInicio;
	
	if(pInicio==NULL){
		cout<<"La lista esta vacia";
	}
	while(p!=NULL){
		cout<<p->dato<<" ";
		p=p->sig;
	}
}
//Funcion que guarda datos pares en ontra lista
void insertarnodopar(nodo *&pIniciopar,int dato){
	nodo *nuevo;
	nuevo = new nodo;
	nuevo->dato=dato;
	nuevo->sig=pIniciopar;
	pIniciopar=nuevo;
}
//Funcion que guarda datos impares en ontra lista
void insertarnodoimpar(nodo *&pInicioimpar,int dato){
	nodo *nuevo;
	nuevo = new nodo;
	nuevo->dato=dato;
	nuevo->sig=pInicioimpar;
	pInicioimpar=nuevo;
}
//Funcion que busca el par y el impar
void buscapareimpar(nodo *&pInicio, nodo *&pIniciopar, nodo *&pInicioimpar){
	int aux1, aux2;
	nodo *s;
	while(pInicio!=NULL){
		s=pInicio;
		if(s->dato%2==0){
			aux1=s->dato;
			insertarnodopar(pIniciopar,aux1);
		}else{
			aux2=s->dato;
			insertarnodoimpar(pInicioimpar,aux2);
		}
		pInicio=pInicio->sig;
		delete s;
	 }
}
int main(void){
	nodo *pInicio=NULL;
	nodo *pIniciopar=NULL;
	nodo *pInicioimpar=NULL;
	
	char resp;
	int dato;
	
	cout<<"Desea ingresar un dato (s/n)? ";
	cin>>resp;
	while(resp=='s' || resp=='S'){
		cout<<"Ingrese el dato: ";
		cin>>dato;
		insertarnodo(dato,pInicio);
		cout<<"Desea Ingresar otro dato (s/n)? ";
		cin>>resp;
	}
		
	cout<<"\nLa lista ingresada es: ";
	mostrarlista(pInicio);
	
	buscapareimpar(pInicio, pIniciopar, pInicioimpar);
	cout<<"\nLa lista con numeros pares es: ";
	mostrarlista(pIniciopar);
	cout<<"\nLa lista con numeros impares: ";
	mostrarlista(pInicioimpar);
	
	cout<<"\nLa lista original ingresada: ";
	mostrarlista(pInicio);
	
	return 0;
}
