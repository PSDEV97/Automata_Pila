using namespace std;

class Stack{
	
	private:
		
		List *top;
	public:
		
		Stack(){// constructor de la clase pila
			top=NULL;
		}
		
		bool emptyStack(){// funcion para determinar si la pila esta vacia
			return top == NULL;
		}
		
		void insertDataStack(DATA data){//insertar un nodo a la pila
			List *auxiliaryNode = new List();
			auxiliaryNode-> data = data;
			auxiliaryNode-> following = top;
			top = auxiliaryNode;
		}
		
		DATA removeDataStack(){//sacar un dato de la pila
			List *auxiliaryNode;
			DATA auxiliary;
			if (!emptyStack()){
				auxiliaryNode = top;
				top = top -> following;
				auxiliary = auxiliaryNode -> data;
				delete (auxiliaryNode);
				return auxiliary;
			}else{
				cout << "underflow";
			}
		}
		
		int stackSize(){//indica el tamaño de la pila
			int stackSize = 0;
			List *auxiliary = top;
			while(auxiliary != NULL){
				stackSize++;
				auxiliary = auxiliary -> following;
			}
			return stackSize;
		}
		void empty(){// vacia la pila
			List *auxiliary = top;
			while(top != NULL){
				auxiliary = top;
				top = top -> following;
				delete (auxiliary);
			}
		}
		
		void print(){
			List *auxiliary = top;
			while(auxiliary != NULL){
				cout << "[" << auxiliary -> data << "]" <<endl;
				auxiliary = auxiliary -> following;
			}
		}
};
