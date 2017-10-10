class Vertex{
	protected:
		string name;
		int vertexNumber;
		bool status;
	public:
		Vertex(){
		}

		Vertex(string name){
			this->name = name;
			this->vertexNumber = -1;
			this->status = false;
		}

		Vertex(string name,int vertexNumber){
			this->name = name;
			this->vertexNumber = vertexNumber;
			this->status = false;
		}
	
		Vertex(string name,int vertexNumber,bool status){
			this->name = name;
			this->vertexNumber = vertexNumber;
			this->status = status;
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
	
		bool getStatus(){
			return this->status;
		}
		
		void setStatus(bool status){
			this->status = status;
		}
};
