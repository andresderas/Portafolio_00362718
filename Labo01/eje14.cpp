#include <iostream>
#include <string.h>

using namespace std;

void palindrome(char *,char *,int);
int main(void){
	
	char palabra[25];
	cout<<"Ingrese una palabra: ";
	cin>>palabra;
	int lon=strlen(palabra);
	
	char palabra2[lon];
	
	palindrome(palabra2,&palabra[lon-1],lon);
	
	int result=strcmp(palabra2,palabra);
	if(result==0){
		cout<<"La palabra ingresada es palindrome";
	}else{
		cout<<"La palabara ingresada no es palindorme";
	}
	return 0;
}

void palindrome(char *p,char *q,int lon){
	if(lon>=0){
		*p=*q;
		palindrome(p+1,q-1,lon-1);
	}
}

