#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct nodo{
	string nombre, apellido, carnet, telefono, correo;
	int edad; 
	nodo *sig;
};

class datos{
	private:
		nodo *pInicio;
		
	public:
		datos(void);
		void insertnodo(int,string,string,string,string,string);
		void menu(void);
		void eliminarnodo(string);
		void actualizar(string);
		void mostrarlista(void);
};

datos::datos(void){
	pInicio=NULL;
}
//Funcion que agrega nodos a la lista
void datos::insertnodo(int edad, string nombre, string apellido, string carnet, string tel, string correo){
	nodo *nuevo;
	nuevo= new nodo;
	nuevo->carnet=carnet;
	nuevo->nombre=nombre;
	nuevo->apellido=apellido;
	nuevo->edad=edad;
	nuevo->telefono=tel;
	nuevo->correo=correo;
	nuevo->sig=pInicio;
	pInicio=nuevo;	
}
//Funcion que elimina nodo
void datos::eliminarnodo(string nombre){
	nodo *p, *q;
	p=pInicio;
	q=NULL;
	while(p!=NULL && p->nombre!=nombre){
		q=p;
		p=p->sig;
	}
	if(p!=NULL){
		if(q!=NULL){
			q->sig=p->sig;
			delete p;
			cout<<"Persona borrada exitosamente"<<endl;
		}else{
			pInicio=p->sig;
			delete p;
			cout<<"Persona borrada exitosamente"<<endl;
		}
	}else{
		cout<<"Persona a borrar no existe."<<endl;
	}
}
//Funcio que busca un nodo para actualizar ls datos de una persona
void datos::actualizar(string nombre){
	nodo *s=pInicio;
	char resp;
	string nombre2, apellido, carnet, telefono, correo;
	int edad;
	
	while(s!=NULL && s->nombre!=nombre){
		s=s->sig;
	}
	
	if(s==NULL){
		cout<<"Persona no encontrada."<<endl;
	}else{
	
		cout<<"Que dato desea actualizar?"<<endl;
		cout<<"A. Carnet"<<endl;
		cout<<"B. Nombre"<<endl;
		cout<<"C. Apellido"<<endl;
		cout<<"D. Edad"<<endl;
		cout<<"E. Numero de telefono"<<endl;
		cout<<"F. Correo electronico"<<endl;
		cout<<"Ingrese la letra del dato que desea actualizar: ";
		cin>>resp;
				
		switch(resp){
			case 'a':
				case'A':
					cout<<"Ingrese el nuevo carnet: ";
					cin>>carnet;
					s->carnet=carnet;
					break;
			case 'b':
				case 'B':
					cout<<"Ingrese el nuevo nombre: ";
					cin>>nombre2;
					s->nombre=nombre2;
					break;
			case 'c':
				case 'C':
					cout<<"Ingrese el nuevo apellido: ";
					cin>>apellido;
					s->apellido=apellido;
					break;
			case'd':
				case 'D':
					cout<<"Ingrese la nueva edad: ";
					cin>>edad;
					s->edad=edad;
					break;
			case 'e':
				case 'E':
					cout<<"Ingrese el nuevo numero de telefono: ";
					cin>>telefono;
					s->telefono=telefono;
					break;
			case 'f':
				case 'F':
					cout<<"Ingrese el nuevo correo electronico: ";
					cin>>correo;
					s->correo=correo;
					break;
			default:
				cout<<"Opcion ingresada no valida."<<endl;
				break;
		}
	}
}
//Funcio que muestra a todas las personas
void datos::mostrarlista(void){
	nodo *s=pInicio;
	if(pInicio==NULL){
		cout<<"La lista esta vacia."<<endl;;
	}
	while(s!=NULL){
		cout<<"La persona ingresada es: "<<s->nombre<<" "<<s->apellido<<endl;
		cout<<"Carnet: "<<s->carnet<<endl;
		cout<<"Edad: "<<s->edad<<endl;
		cout<<"Numero de telefono: "<<s->telefono<<endl;
		cout<<"Correo electronico: "<<s->correo<<endl<<endl;
		s=s->sig;
	}
}
//Funcion que crea menu
void datos::menu(void){
	int opc, edad;
	string nombre, apellido, carnet, telefono, correo;
	
	do{
	
		cout<<".:MENU:."<<endl;
		cout<<"1. Agregar persona."<<endl;
		cout<<"2. Eliminar una persona."<<endl;
		cout<<"3. Actualizar los datos de una persona."<<endl;
		cout<<"4. Mostrar todas las personas."<<endl;
		cout<<"5. Salir."<<endl;
		cout<<"\nIngrese opcion: ";
		cin>>opc;
		cout<<endl;
	
	
		switch(opc){
			case 1: 
				cout<<"Ingrese el nombre de la persona: ";
				cin>>nombre;
				cout<<"Ingrese el apellido: ";
				cin>>apellido;
				cout<<"Ingrese el carnet: ";
				cin>>carnet;
				cout<<"Ingrese la edad: ";
				cin>>edad;
				cout<<"Ingrese el numero de telefono: ";
				cin>>telefono;
				cout<<"Ingrese el correo: ";
				cin>>correo;
				insertnodo(edad,nombre,apellido,carnet,telefono,correo);
				system("pause");
				break;
			case 2:
				cout<<"Ingrese el nombre de la persona a eliminar: ";
				cin>>nombre;
				eliminarnodo(nombre);
				system("pause");
				break;
			case 3:
				cout<<"Ingrese el nombre de la persona a actualizar: ";
				cin>>nombre;
				actualizar(nombre);
				system("pause");
				break;
			case 4:
				mostrarlista();
				system("pause");
				break;
			default:
				cout<<"Opcion ingresada no valida.";
				system("pause");
				break;
		}
		system("cls");
	}while(opc!=5);
}
//Funcion main
int main(void){
	datos miLista;
	miLista.menu();
	
	return 0;
}
