#include<iostream>
#include "Lista.h"
#include "Pila.h"
using namespace std;
main (){
	Pila p; 
	dato Dato;
	cout<<"Ingresar Valor a La Pila:"<<endl;
	for(int i=0; i<3; i++){
    	cin>>Dato;
	    p.insert(Dato);
	}
	cout<<endl;
	p.imprimir();	
}




