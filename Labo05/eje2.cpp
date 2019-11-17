#include <iostream>
using namespace std;
//Variables globales
int contadorp=0;
int sumap=0;
int contadori=0;
int sumai=0;
int contadorn=0;
int contadorpo=0;
int contadorc=0;
struct nodo{
	int dato;
	nodo *hijoizq;
	nodo *hijoDer;
};

class ABB{
	private: 
		nodo *pArbol;
	public:
		ABB(void);
		void mostrarIn(void);
		void mostrarIn(nodo *);
		void pares();
		void pares(nodo *);
		void negativos();
		void negativos(nodo *);
		void insNodo(int);
		void insNodo(nodo **, int);
		void operaciones(void);
};
//Funcion iniciadora
ABB::ABB(void){
	pArbol=NULL;
}
//Funcion que manda pArbol
void ABB::insNodo(int dato){
	insNodo(&pArbol,dato);
}
//Funcion que incerta Nodo
void ABB::insNodo(nodo **p,int dato){
	if(!(*p)){
		*p=new nodo;
		(*p)->dato=dato;
		(*p)->hijoizq=(*p)->hijoDer=NULL;
	}else{
		if(dato<(*p)->dato){
 			insNodo(&((*p)->hijoizq),dato);
		}else{
			if(dato>(*p)->dato){
				insNodo(&((*p)->hijoDer),dato);
			}else{
				cout<<"El nodo ya existe\n";
			}
		}
	}
}
//Funcion que manda pArbol
void ABB::pares(void){
	pares(pArbol);
}
//Funcion que busca pares e impares
void ABB::pares(nodo *p){
	if(p){
		pares(p->hijoizq);
		if(p->dato%2==0){
			contadorp++;
			sumap=sumap+p->dato;
		}else{
			contadori++;
			sumai=sumai+p->dato;
		}
		pares(p->hijoDer);
	}
}
//Funcion que manda pArbol
void ABB::negativos(void){
	negativos(pArbol);
}
//Funcion que busca negativos y positivos
void ABB::negativos(nodo *p){
	if(p){
		negativos(p->hijoizq);
		if(p->dato==0){
			contadorc++;
		}else if(p->dato>0){
			contadorpo++;
		}else{
			contadorn++;
		}
		negativos(p->hijoDer);
	}
}
//Funcion que manda pArbol
void ABB::mostrarIn(void){
	mostrarIn(pArbol);
}
//Funcion que muestra contenido de arbol de forma inorden
void ABB::mostrarIn(nodo *p){
	if(p){
		mostrarIn(p->hijoizq);
		cout<<p->dato<<endl;
		mostrarIn(p->hijoDer);
	}
}
//Funcio que realiza todas las operaciones del arbol
void ABB::operaciones(void){
	char resp;
	int dato;
	
	cout<<"Desea meter un dato (s/n)? ";
	cin>>resp;
	while(resp=='s' || resp=='S'){
		cout<<"Digite el dato: ";
		cin>>dato;
		insNodo(dato);
		cout<<"Desea meter un dato (s/n)? ";
		cin>>resp;
	}
	
	cout<<"\nMostrar In-orden (ascendente):"<<endl;
	mostrarIn();

	pares();
	cout<<"\nEl arbol tiene "<<contadorp<<" numeros pares"<<endl;
	cout<<"La suma de los numero pares es: "<<sumap<<endl;
	cout<<"\nEl arbol tiene "<<contadori<<" numeros impares"<<endl;
	cout<<"La suma de los numero impares es: "<<sumai<<endl;
	
	negativos();
	cout<<"\nEl arbol tiene "<<contadorc<<" cero/s"<<endl;
	cout<<"El arbol tiene "<<contadorn<<" numeros negativos"<<endl;
	cout<<"El arbol tiene "<<contadorpo<<" numeros positivos"<<endl;
}
//Funcio MAIN
int main(void){
	ABB miArbol;
	miArbol.operaciones();
	return 0;
}
