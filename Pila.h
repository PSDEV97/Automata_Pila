using namespace std;

class Pila{
	
	private:
		
		List *tope;
	public:
		
		Pila(){
			tope=NULL;
		}
		
		bool pilaVacia(){
			return tope == NULL;
		}
		
		void insert(dato d){
			List *nodo = new List();
			nodo->Dato = d;
			nodo->siguiente = tope;
			tope = nodo;
		}
		
		dato remove(){//saca un dato de la pila
			List *nodoAuxiliar;
			dato auxiliar;
			if (!pilaVacia()){
				nodoAuxiliar = tope;
				tope = tope->siguiente;
				auxiliar = nodoAuxiliar->Dato;
				delete (nodoAuxiliar);
				return auxiliar;
			}else{
				cout << "underflow";
			}
		}
		
		int stackSize(){//indica el tamaño de la pila
			int tamanoPila = 0;
			List *p = tope;
			while(p != NULL){
				tamanoPila++;
				p = p -> siguiente;
			}
			return tamanoPila;
		}
		void empty(){// vacia la pila
			List *p = tope;
			while(tope != NULL){
				p = tope;
				tope = tope -> siguiente;
				delete (p);
			}
		}
		
		void imprimir(){
			List *p = tope;
			while(p != NULL){
				cout << "[" << p->Dato << "]" <<endl;
				p = p->siguiente;
			}
		}
};
