//interfaz de la clase Pila
// Oscar Perez Sampayo
// Dayana Bustamante Cuello

#include <iostream>
using namespace std;

template <class T>
class Pila
{
	class NodoPila
	{
		public:
			NodoPila* siguiente;
			T elemento;
			NodoPila(T x);
			{
				elemento = x;
				siguiente = NULL;
			}
	};
	NodoPila* cima;

	public:
		Pila();
		void insertar();
		T quitar();
		T cimaPila(); const
		bool pilaVacia(); const
		void limpiarPila();
		
};		  	
	

