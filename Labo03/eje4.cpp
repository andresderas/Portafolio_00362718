#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};

class ListaSimple{
	private:
		nodo *pInicio;
		
	public:
		
		ListaSimple(void);
		void insertarinicioLista(int);
		void mostrarLista(int,int);
};

ListaSimple::ListaSimple(void){
	cout<<"Inicializando el objeto"<<endl;
	pInicio = NULL;
}
void ListaSimple::insertarinicioLista(int dato){
	nodo *nuevo;
			
	//new crea un espacio de memoria para lo que le ha pasado y retorna un espacio de memoria.
	nuevo = new nodo;
	nuevo->dato = dato;
	nuevo->sig = pInicio;
	pInicio = nuevo;
}
	
//Mostrando lista con un saltarin de forma iterativa (lazo)	
void ListaSimple::mostrarLista(int p, int i){
	nodo *s = pInicio;

	while(s!=NULL){
		if(s->dato%2==0){
			p+=s->dato;
		}else{
			i+=s->dato;
		}
		s=s->sig;
	}
	cout<<"\nLa suma de los numeros pares de la lista es: "<<p<<endl;
	cout<<"La suma de los numeros impares de la lista es: "<<i<<endl;
}
//Funcion MAIN
int main (void){
	
	ListaSimple miLista;
	char resp;
	int dato;
	int datoBuscar;
	int sumapar=0;
	int sumaimpar=0;
	
	cout<<"Desea meter un dato (s/n)? ";
	cin>>resp;
	while(resp=='s'){
		cout<<"Digite el dato: ";
		cin>>dato;
		miLista.insertarinicioLista(dato);
		cout<<"Desea meter un dato (s/n)? ";
		cin>>resp;
	}
	
	miLista.mostrarLista(sumapar,sumaimpar);
	
	return 0;	
}
