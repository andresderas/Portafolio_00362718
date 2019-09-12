#include <iostream>
using namespace std;

void cod(char*, int);
int main (void){
	
	char arreglo []="murcielago";
	int tam;
	tam=sizeof(arreglo);
	cout<<"La palabra sin codificar es: "<<arreglo<<endl;
	
	cout<<"La palabra codificada es: ";
	cod(arreglo,tam);
	
return 0;
}

void cod(char*p, int tam){

	for(int i=0;i<tam;i++){
		if(*p=='m'){
			cout<<"0";
		}
		else if(*p=='u'){
			cout<<"1";
	  	}
		else if(*p=='r'){
			cout<<"2";
		}
		else if(*p=='c'){
			cout<<"3";
		}
		else if(*p=='i'){
			cout<<"4";
		}
		else if(*p=='e'){
			cout<<"5";
		}
		else if(*p=='l'){
			cout<<"6";
		}
		else if(*p=='a'){
			cout<<"7";
		}
		else if(*p=='g'){
			cout<<"8";
		}
		else if(*p=='o'){
			cout<<"9";
		}
		else{
			cout<<*p;
		}
		p++;
	}
}
