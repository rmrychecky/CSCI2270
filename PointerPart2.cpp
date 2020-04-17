struct Person
{
  string name;
  int age;
};

int main()
{
  Person p1; //instance of person
  Person *ptr; //pointer to person type 
  ptr = &p1;
}

//syntax for accessing members of struct via pointer
  (*ptr).name = "Alaba";
  (*ptr).age = 27;
  //equivalent
  ptr -> name = "Alaba";
  ptr -> age = 27
//these populate the instance of a struct!

cout << ptr->name << endl; //will print out name

//“New” and “delete”

int *p1; 
p1 = new int; //allocates memory in the heap for an int and uses a pointer

delete p1; //deallocating memory but still points to space
p1 = NULL; //now pointer is pointing to nothing
//aka freeing the memory back to the heap

int n;
int *ptr;
n = 5;
ptr = new int[n]; //array in the heap
for (int i = 0; i < n; i++)
{
  cin >> ptr[i];
}