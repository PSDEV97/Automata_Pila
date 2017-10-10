
class MatrixGraph{
	protected:
		int maximumVertex;
		int numberVertices; 
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
	
		char newVertex(string vertexName){
			bool esta = vertexSearch(vertexName) >= 0;
			if(!esta){
				Vertex auxiliary = Vertex(vertexName, numberVertices);
				vertex[numberVertices++] = auxiliary;
				return '0';
			}else{
				return '1';//cout << "No se puede insertar. Ya esta!" << endl;
			}
		}
	
		int vertexSearch(string vertexName){ 
			int vertexPosition;
			bool found = false;
			for( vertexPosition = 0; (vertexPosition < numberVertices) && !found;){
				found = vertex[vertexPosition].sameName(vertexName);
				if(!found){
					vertexPosition++;
				}
			}
			if(vertexPosition < numberVertices){
				return vertexPosition;
			}else{
				return -1;
			}
		}
		char newBow(string vertexNameA, string vertexNameB){
			int vertexPositionA, vertexPositionB; //vertexPosition
			vertexPositionA = vertexSearch(vertexNameA);
			vertexPositionB = vertexSearch(vertexNameB);
			if(vertexPositionA < 0 || vertexPositionB < 0){
				return '2';// cout << "Vertice no existe" << endl;
			}else{
				adjacencyMatrix[vertexPositionA][vertexPositionB] = 1;
				return '0';
			}
		}
		char newBow(string vertexNameA, string vertexNameB,int arcValue){
			int vertexPositionA, vertexPositionB; //vertexPosition
			vertexPositionA = vertexSearch(vertexNameA);
			vertexPositionB = vertexSearch(vertexNameB);
			
			if(vertexPositionA < 0 || vertexPositionB < 0){
				return '2';// cout << "Vertice no existe" << endl;
			}else{
				adjacencyMatrix[vertexPositionA][vertexPositionB] = arcValue;
				return '0';
			}
		}
		char newBow(int vertexPositionA, int vertexPositionB){
			if(vertexPositionA < 0 || vertexPositionB < 0 || vertexPositionA > numberVertices || vertexPositionB > numberVertices){
				return '2'; //cout << "Vertice no existe" << endl;
			}else{
				adjacencyMatrix[vertexPositionA][vertexPositionB] = 1;
				return '0';
			}
		}
	
		char newBow(int vertexPositionA, int vertexPositionB, int arcValue){
			if(vertexPositionA < 0 || vertexPositionB < 0 || vertexPositionA > numberVertices || vertexPositionB > numberVertices){
				return '2'; //cout << "Vertice no existe" << endl;
			}else{
				adjacencyMatrix[vertexPositionA][vertexPositionB] = arcValue;
				return '0';
			}
		}
	
		bool adjacentVertices(string vertexNameA, string vertexNameB){ //adjacentVertices
			int vertexPositionA = numVertices(vertexNameA);
			int vertexPositionB = numVertices(vertexNameB);
			if(vertexPositionA < 0 || vertexPositionB < 0){
				//cout << "Vertice no existe" << endl;
				return false;
			}else{
				return adjacencyMatrix[vertexPositionA][vertexPositionB] >= 1;
			}
		}
		bool adjacentVertices(int vertexPositionA, int vertexPositionB){ //adjacentVertices
			if(vertexPositionA < 0 || vertexPositionB < 0 || vertexPositionA > numberVertices || vertexPositionB > numberVertices){//a<b
				//cout << "Vertice no existe" << endl;
				return false;
			}else{
				return adjacencyMatrix[vertexPositionA][vertexPositionB] >= 1;
			}
		}
		int getValue(int vertexPositionA, int vertexPositionB){
			if(vertexPositionA < 0 || vertexPositionB < 0 || vertexPositionA > numberVertices || vertexPositionB > numberVertices){
				//cout << "Vertice no existe" << endl;
				return -1;
			}else{
				return adjacencyMatrix[vertexPositionA][vertexPositionB]; //>=1
			}
		}
		int getValue(string vertexNameA, string vertexNameB){
				int vertexPositionA, vertexPositionB;
				vertexPositionA = numVertices(vertexNameA);
				vertexPositionB = numVertices(vertexNameB);
				if (vertexPositionA < 0 || vertexPositionB < 0)	{
					// cout << "vertice no existe";
					return -1;
				}else{
					return adjacencyMatrix[vertexPositionA][vertexPositionB];
				}
		}
		 char setValue(int vertexPositionA, int vertexPositionB, int arcValue){
			if(vertexPositionA < 0 || vertexPositionB < 0 || vertexPositionA > numberVertices || vertexPositionB > numberVertices){
				//cout << "vertice no existe..";
				return '2';
			}else{
				adjacencyMatrix[vertexPositionA][vertexPositionB] = arcValue;
				return '0';
			}
		}

		char setValor(string vertexNameA, string vertexNameB, int arcValue){
			int vertexPositionA, vertexPositionB;
			vertexPositionA = numVertices(a);
			vertexPositionB = numVertices(b);
			if(vertexPositionA < 0 || vertexPositionB < 0){
				return '2';//cout << "vertice no existe..";
			}else{
				adjacencyMatrix[vertexPositionA][vertexPositionB] = arcValue;
				return '0';
			}
		}
		Vertex getVertex(int vertexPosition){
			if(vertexPosition < 0 || vertexPosition >= numberVertices){
				//return '2'; //cout << "Vertice no existe..";
			}else{
				return vertex[vertexPosition];
				//return '0';
			}
		}

		char setVertex(int vertexPosition, Vertex vertex){
			if( vertexPosition < 0 || vertexPosition >= numberVertices){
				return '2';//cout << "Vertice no existe..";
			}else{
				vertex[vertexPosition] = vertex;
				return '0';
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

