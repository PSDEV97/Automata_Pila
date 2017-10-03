
class MatrixGraph{
	protected:
		int maximumVertex;
		int numberVertices; //numberVertices
		Vertex *vertex;
		int **adjacencyMatrix;
	public:
		MatrixGraph(){
			maximumVertex = 1;
			MatrixGraph(maximumVertex);
		}

		MatrixGraph(int maximumVertex){
			this->maximumVertex = maximumVertex;
			this->vertex = new Vertex[maximumVertex];
			this->adjacencyMatrix = new int *[maximumVertex];
			this->numberVertices = 0;
			for(int i = 0; i < maximumVertex; i++){
				this->adjacencyMatrix[i] = new int [maximumVertex];
				for(int j = 0; j < maximumVertex; j++){
					this->adjacencyMatrix[i][j] = 0;
				}
			}
		}

		int getNumberVertices(){
			return this->numberVertices;
		}
	
		void setNumberVertices(int numberVertices){
			this->numberVertices = numberVertices;
		}
	
		void newVertex(string vertexName){
			bool esta = numVertices(vertexName) >= 0;
			if(!esta){
				Vertex auxiliary = Vertex(vertexName, numberVertices);
				vertex[numberVertices++] = auxiliary;
			}else{
				cout << "No se puede insertar. Ya esta!" << endl;
			}
		}
	
		int numVertices(string vertexName){
			int i;
			bool encontrado = false;
			for( i = 0; (i < numberVertices) && !encontrado;){
				encontrado = vertex[i].sameName(vertexName);
				if(!encontrado){
					i++;
				}
			}
			if(i < numberVertices){
				return i;
			}else{
				return -1;
			}
		}
		void newBow(string vertexNameA, string vertexNameB){
			int va, vb;
			va = numVertices(vertexNameA);
			vb = numVertices(vertexNameB);
			if(va < 0 || vb < 0){
				cout << "Vertice no existe" << endl;
			}else{
				adjacencyMatrix[va][vb] = 1;
			}
		}
		void newBow(string vertexNameA, string vertexNameB,int valor){
			int va, vb;
			va = numVertices(vertexNameA);
			vb = numVertices(vertexNameB);
			if(va < 0 || vb < 0){
				cout << "Vertice no existe" << endl;
			}else{
				adjacencyMatrix[va][vb] = valor;
			}
		}
		void newBow(int va, int vb){
			if(va < 0 || vb < 0 || va > numberVertices || vb > numberVertices){
				cout << "Vertice no existe" << endl;
			}else{
				adjacencyMatrix[va][vb] = 1;
			}
		}
		void newBow(int va, int vb, int valor){
			if(va < 0 || vb < 0 || va > numberVertices || vb > numberVertices){
				cout << "Vertice no existe" << endl;
			}else{
				adjacencyMatrix[va][vb] = valor;
			}
		}
		bool adyacentes(string a, string b){ //adjacentVertices
			int va = numVertices(a);
			int vb = numVertices(b);
			if(va < 0 || vb < 0){
				cout << "Vertice no existe" << endl;
				return false;
			}else{
				return adjacencyMatrix[va][vb] >= 1;
			}
		}
		bool adyacentes(int a, int b){ //adjacentVertices
			if(a < 0 || b < 0 || a > numberVertices || b > numberVertices){//a<b
				cout << "Vertice no existe" << endl;
				return false;
			}else{
				return adjacencyMatrix[a][b] >= 1;
			}
		}
		int getValor(int a, int b){
			if(a < 0 || b < 0 || a > numberVertices || b > numberVertices){
				cout << "Vertice no existe" << endl;
				return -1;
			}else{
				return adjacencyMatrix[a][b]; //>=1
			}
		}
		int getValor(string a, string b){
				int va, vb;
				va = numVertices(a);
				vb = numVertices(b);
				if (va < 0 || vb < 0)	{
					cout << "vertice no existe";
					return -1;
				}else{
					return adjacencyMatrix[va][vb];
				}
		}
		void setValor(int a, int b, int v){
			if(a < 0 || b < 0 || a > numberVertices || b > numberVertices){
				cout << "vertice no existe..";
			}else{
				adjacencyMatrix[a][b] = v;
			}
		}

		void setValor(string a, string b, int v){
			int va, vb;
			va = numVertices(a);
			vb = numVertices(b);
			if(va < 0 || vb < 0){
				cout << "vertice no existe..";
			}else{
				adjacencyMatrix[va][vb] = v;
			}
		}
		Vertex getVertice(int n){
		if(n < 0 || n >= numberVertices){
			cout << "Vertice no existe..";
		}else{
			return vertex[n];
		}
	}

	void setVertice(int n, Vertex v){
			if( n < 0 || n >= numberVertices){
			cout << "Vertice no existe..";
		}else{
			 vertex[n] = v;
		}
	}
	void impVerts(){
		cout << "V:{";
		for(int i = 0; i < numberVertices; i++){
			cout << "[" << vertex[i].getName() << "]";
		}
		cout << "}" << endl;
	}

	void printAdjacencyMatrix(){
		cout << "adjacencyMatrix:" << endl;
		for(int i = 0; i < numberVertices ; i++){
			for(int j = 0; j < numberVertices; j++){
				cout << "[";
				if(adjacencyMatrix[i][j] == 0)
					cout << setfill(' ') << setw(3) << (" ");
				else
					cout << setfill(' ') << setw(3) << adjacencyMatrix[i][j];
				cout<<"]";
			}
			cout << endl;
		}
	}
	void printFormalAdjacencyMatrix(){
			cout << "adjacencyMatrix:{";
			for(int i = 0; i < numberVertices; i++){
				for(int j = 0; j < numberVertices; j++){
					if(adjacencyMatrix[i][j] >= 1){
						cout << "(" << vertex[i].getName() << "," << vertex[j].getName() << "),";
					}

				}
			}
			cout << "}" << endl;
		}
	void impGrados(){
			int ce,cs;
			for(int i = 0; i < numberVertices; i++){
				cs = 0;
				ce = 0;
				for(int k = 0; k < numberVertices; k++){
					if(adjacencyMatrix[i][k] >= 1){
						cs++;
						if(adjacencyMatrix[k][i] >= 1){
							ce++;
						}
					}
				}
				cout << vertex[i].getName() << ": sal :" << cs << "       ent:" << ce << "     total: " << ce+cs << endl;
			}
		}
};

