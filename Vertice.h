class Vertex{
	protected:
		string name;
		int vertexNumber;
	public:
		Vertex(){
		}

		Vertex(string name){
			this->name = name;
			this->vertexNumber = -1;
		}

		Vertex(string name,int vertexNumber){
			this->name = name;
			this->vertexNumber = vertexNumber;
		}

		bool sameName(string name){
			return this->name == name;
		}

		string getName(){
			return this->name;
		}

		void setName(string name){
			this->name = name;
		}

		int getVertexNumber(){
			return this->vertexNumber;
		}

		void setVertexNumber(int vertexNumber){
			this->vertexNumber = vertexNumber;
		}
};
