
class MatrixGraph{
	protected:
		int maximumVertex;
		int numVerts; //numberVertices
		Vertex *vertex;
		int **adjacencyMatrix;
	public:
		MatrixGraph(){
			maximumVertex = 1;
			MatrixGraph(maximumVertex);
		}

		MatrixGraph(int mx){
			maximumVertex = mx;
			vertex = new Vertex[mx];
			adjacencyMatrix = new int *[mx];
			numVerts=0;
			for(int i=0; i<mx;i++){
				adjacencyMatrix[i]=new int [mx];
				for(int j=0;j<mx;j++){
					adjacencyMatrix[i][j]=0;
				}
			}
		}

		int getNumVertices(){
			return numVerts;
		}
		void setNumVertices(int n){
			numVerts=n;
		}
		void nuevoVertice(string nom){
			bool esta=numVertices(nom)>=0;
			if(!esta){
				Vertex v= Vertex(nom,numVerts);
				vertex[numVerts++]=v;
			}else{
				cout<<"No se puede insertar. Ya esta!"<<endl;
			}
		}
		int numVertices(string v){
			int i;
			bool encontrado=false;
			for(i=0;(i<numVerts)&&!encontrado;){
				encontrado=vertex[i].sameName(v);
				if(!encontrado){
					i++;
				}
			}
			if(i<numVerts){
				return i;
			}else{
				return -1;
			}
		}
		void nuevoArco(string a, string b){
			int va, vb;
			va=numVertices(a);
			vb=numVertices(b);
			if(va<0||vb<0){
				cout<<"Vertice no existe"<<endl;
			}else{
				adjacencyMatrix[va][vb]=1;
			}
		}
		void nuevoArco(string a, string b,int valor){
			int va, vb;
			va=numVertices(a);
			vb=numVertices(b);
			if(va<0||vb<0){
				cout<<"Vertice no existe"<<endl;
			}else{
				adjacencyMatrix[va][vb]=valor;
			}
		}
		void nuevoArco(int va, int vb){
			if(va<0||vb<0||va>numVerts||vb>numVerts){
				cout<<"Vertice no existe"<<endl;
			}else{
				adjacencyMatrix[va][vb]=1;
			}
		}
		void nuevoArco(int va, int vb, int valor){
			if(va<0||vb<0||va>numVerts||vb>numVerts){
				cout<<"Vertice no existe"<<endl;
			}else{
				adjacencyMatrix[va][vb]=valor;
			}
		}
		bool adyacentes(string a, string b){
			int va=numVertices(a);
			int vb=numVertices(b);
			if(va<0||vb<0){
				cout<<"Vertice no existe"<<endl;
				return false;
			}else{
				return adjacencyMatrix[va][vb]>=1;
			}
		}
		bool adyacentes(int a, int b){
			if(a<0||b<0||a>numVerts||b>numVerts){//a<b
				cout<<"Vertice no existe"<<endl;
				return false;
			}else{
				return adjacencyMatrix[a][b]>=1;
			}
		}
		int getValor(int a, int b){
			if(a<0||b<0||a>numVerts||b>numVerts){
				cout<<"Vertice no existe"<<endl;
				return -1;
			}else{
				return adjacencyMatrix[a][b]; //>=1
			}
		}
		int getValor(string a, string b){
				int va, vb;
				va=numVertices(a);
				vb=numVertices(b);
				if (va<0||vb<0)	{
					cout<<"vertice no existe";
					return -1;
				}else{
					return adjacencyMatrix[va][vb];
				}
		}
		void setValor(int a, int b, int v){
			if(a<0||b<0||a>numVerts||b>numVerts){
				cout<<"vertice no existe..";
			}else{
				adjacencyMatrix[a][b]=v;
			}
		}

		void setValor(string a, string b, int v){
			int va, vb;
			va=numVertices(a);
			vb=numVertices(b);
			if(va<0||vb<0){
				cout<<"vertice no existe..";
			}else{
				adjacencyMatrix[va][vb]=v;
			}
		}
		Vertex getVertice(int n){
		if(n<0||n>=numVerts){
			cout<<"Vertice no existe..";
		}else{
			return vertex[n];
		}
	}

	void setVertice(int n, Vertex v){
			if(n<0||n>=numVerts){
			cout<<"Vertice no existe..";
		}else{
			 vertex[n]=v;
		}
	}
	void impVerts(){
		cout<<"V:{";
		for(int i=0; i<numVerts; i++){
			cout<<"["<<vertex[i].getName()<<"]";
		}
		cout<<"}"<<endl;
	}

	void printAdjacencyMatrix(){
		cout<<"adjacencyMatrix:"<<endl;
		for(int i=0;i<numVerts;i++){
			for(int j=0;j<numVerts;j++){
				cout<<"[";
				if(adjacencyMatrix[i][j]==0)
				cout << setfill(' ')<<setw(3)<<(" ");
				else
				cout<<setfill(' ')<<setw(3)<<adjacencyMatrix[i][j];
				cout<<"]";
			}
			cout<<endl;
		}
	}
	void printFormalAdjacencyMatrix(){
			cout<<"adjacencyMatrix:{";
			for(int i=0;i<numVerts;i++){
				for(int j=0;j<numVerts;j++){
					if(adjacencyMatrix[i][j]>=1){
						cout<<"("<<vertex[i].getName()<<","<<vertex[j].getName()<<"),";
					}

				}
			}
			cout<<"}"<<endl;
		}
	void impGrados(){
			int ce,cs;
			for(int i=0;i<numVerts;i++){
				cs=0;
				ce=0;
				for(int k=0;k<numVerts;k++){
					if(adjacencyMatrix[i][k]>=1){
						cs++;
						if(adjacencyMatrix[k][i]>=1){
							ce++;
						}
					}
				}
				cout<<vertex[i].getName()<<": sal :"<<cs<<"       ent:"<<ce<<"     total: "<<ce+cs<<endl;
			}
		}
};

