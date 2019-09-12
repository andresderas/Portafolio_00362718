//3(c),13 y 14
 
#include <iostream>
using namespace std;

int func(int);
int funcI(int);
int main(void){
	
	int n;
	cout<<"Ingrese un numero: ";
	cin>>n;
	
	int resp=func(n);
	int resp1=funcI(n);
	cout<<resp<<endl<<resp1;
	
}

int func(int n){
	if(n==0)
		return(0);
	return(n + func(n-1));
}

int funcI(int v){
	int r=0;
	for(int i=v; i>0; i--){
		r+=i;
	}
	return r;
}
