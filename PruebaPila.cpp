#include<iostream>
#include "Lista.h"
#include "Pila.h"
using namespace std;

main (){
	Stack p; 
	DATA data;
	
	cout << "Ingresar Valor a La Pila:" << endl;
	
	for(int i=0; i<3; i++){
    		cin >> data;
		p.insertDataStack(data);
	}
	
	cout << endl;
	p.print();	
}




