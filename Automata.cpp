 // elemento vacio #
 // letras del alfabeto a-z
 // letras de la pila A-Z
 // no realizar accion $


/*
1) ingresar reglas una por una
	- guardar en un arreglo
2) crear una funcion que cree los vertice del grafo segun las reglas del usuario
3) crear una funcion que determine el movimiento entre vertices segun las reglas
4) crear una funcion que lea una palabra y valide si es aceptada o no
5) crear una funcion que grafique el automata

*/
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

#include "Lista.h"
#include "Pila.h"
#include "Vertice.h"
#include "GrafoMatriz.h"

main(){
	string *reglas;

	int numeroReglas = 0;
 	cout << "ingrese el numero de reglas del automata: ";
	cin >> numeroReglas;

	reglas = new string[numeroReglas];
	cout << endl << "ingrese las reglas del automata" << endl;

	for(int i = 0; i < numeroReglas; i++)
		cin >> reglas[i];

    cout << endl;
	for(int i = 0; i < numeroReglas; i++)
	cout << reglas[i] << endl;


}
