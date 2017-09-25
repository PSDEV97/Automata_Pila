//implementacion logica de la clase pila
// Oscar Eduardo Perez Sampayo
// Dayana Paola Bustamante Cuello
#include <iostream>
using namespace std;

#include "Clase_Pila.h"

Pila<T>::Pila() const
{
	cima = NULL;
}

void Pila<T>::insertar(T elemento)
{
	NodoPila* nuevo;
	nuevo = new NodoPila(elemento);
	nuevo -> siguiente = cima;
	cima = nuevo;
}

char Pila<T>::quitar()
{
	if(pilaVacia())
	{
		throw "La pila esta vacia, no se puede extraer.";
	}

	T aux = cima -> elemento;
	cima = cima -> siguiente;
	return aux; 
}
char Pila<T>::cimaPila() const
{
	if(pilaVacia())
	{
		throw "La pila esta vacia, no hay elemetos.";
	}

	return cima -> elemento;
}

bool Pila<T>::pilaVacia()
{
	return cima == NULL;
}

void Pila<T>::limpiarPila()
{
	NodoPila* aux;

	while(!pilaVacia())
	{
		n = cima;
		cima = cima -> siguiente;
		delete n;
	}
}

