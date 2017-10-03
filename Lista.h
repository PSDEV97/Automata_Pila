typedef char DATA;

class List {
	
	public:
		DATA data;
		List *following;
		
		List(){
			following = NULL;
		}
};
