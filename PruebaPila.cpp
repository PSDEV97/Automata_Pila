#include<iostream>
#include "Lista.h"
#include "Pila.h"
using namespace std;

main (){
	Stack pila; 
	DATA data;
	
	cout << "Ingresar Valor a La Pila:" << endl;
	
	for(int i = 0; i < 3; i++){
    		cin >> data;
		pila.insertDataStack(data);
	}
	
	cout << endl;
	pila.print();	
}
