#include <iostream>
using namespace std;

void Pedirdatos(int matrix[5][5]);
void matrix0(int matrix[5][5]);
int main (void){
	
	int matrix [5][5];
	
	matrix0(matrix);
	Pedirdatos(matrix);
	
	//Imprimiedno matriz
	for(int i=0;i<5;i++){
		cout<<"|";
		for(int j=0;j<5;j++){
			cout<<matrix[i][j]<<"\t|";
		}
		cout<<endl;
	}
	
	return 0;
} 

//Funcion que iguala la matriz a 0
void matrix0(int matrix[5][5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			matrix[i][j]=0;
		}
	}
}

//Funcion que llena la diagonal inferior
void Pedirdatos(int matrix[5][5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(i>j || i==j){
				cout<<"Ingresar dato de la matris en la posicion ["<<i<<"]["<<j<<"]:";
				cin>>matrix[i][j];
			}
		}
	}
}
