const in MAXSIZE = 5;

class QueArrCir{
	private:
		int head, tail, queSize; //queSize is like a count
		string a[MAXSIZE];
	public:
		QueArrCir();
		
		bool isEmpty();
		bool isFull();
		void enque(string newItem);
		string deque();
};