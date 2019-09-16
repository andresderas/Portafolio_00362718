#include <iostream>
using namespace std;

int main (){
	
	int n;
	int m;
	cout<<"Ingrese el numero de filas: ";
	cin>>m;
	cout<<"Ingrese el numero de columnas: ";
	cin>>n;
	cout<<endl;
	
	int matrix[m][n];
	//llenando matriz
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<"Ingresar datos de la matriz en la posicion["<<i<<"]["<<j<<"]: ";
			cin>>matrix[i][j];
		}
	}
	//Imprimiendo orginal
	cout<<endl<<"La matriz ingresada es: "<<endl;
	for(int i=0;i<m;i++){
		cout<<"|";
		for(int j=0; j<n; j++){
			cout<<matrix[i][j]<<"\t|";
		}
		cout<<endl;
	}
	//pidiendo fila y columna a quitar
	cout<<endl;
	int m2,n2;
	cout<<"Ingrese la fila a quitar: ";
	cin>>m2;
	cout<<"Ingresa la columna a quitar: ";
	cin>>n2;
	//Quitando fila
	for(int i=m2-1;i<m;i++){
		for(int j=0;j<n;j++){
			matrix[i][j]=matrix[i+1][j];
		}
	}
	//Quitando columna
	for(int i=0;i<m;i++){
		for(int j=n2-1;j<n;j++){
			matrix[i][j]=matrix[i][j+1];
		}
	}
	//creando submatriz
	int matrix2[m-1][n-1];
	for(int i=0;i<m-1;i++){
		for(int j=0;j<n-1;j++){
			matrix2[i][j]=matrix[i][j];
		}
	}
	cout<<endl;
	//Imprimiendo submatriz
	cout<<"La submatriz ingresada es: "<<endl;
	for(int i=0;i<m-1;i++){
		cout<<"|";
		for(int j=0; j<n-1; j++){
			cout<<matrix2[i][j]<<"\t|";
		}
		cout<<endl;
	}

	return 0;
}


