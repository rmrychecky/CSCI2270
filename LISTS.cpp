#define MAX_LIST_SIZE 100
/* Class Declaration */
class List {
  
private:

std::string m_list[MAX_LIST_SIZE]; //List of items
int m_size; // number of items in the list
int m_capacity; // total capacity of the list

public:

List(); // Default Constructor
̃List(); // Default Destructor

int getSize(); // returns number of items in
int getCapacity(); // returns the capacity of
bool isEmpty(); // return true if the list is
bool isFull(); // return true if the list is full; false otherwise

void insert(string data); // insert at item to the end of the list
void insert(string data, int index); // insert an item at a given index
void remove(int index); // remove the item at a given index
int search(string data); // return the index of the first occurence of the given data, -1 otherwise.
string retrieve(int index); //retrieve an item at a given index
void print(); // print the list
 };



//insert operation
void List :: insert (string data, int index)
{
  if((index <0) || (index > m_size))
  {
    throw "Index out of bounds";
  }
  if (m_size < m_capacity)
  {
    for (int i = m_size; i > index; i--)
    {
      m_list[i] = m_list[i-1]; //here you are shifting everything over
    }
    m_list[index] = data; //after everything is shifted, you are going to insert the actual data 
    m_size = m_size + 1; //the size of the list is then increaed by one
  }
  else{
    throw "List capacity reached";
  }
}

//remove operation without gaps
void List :: remove (int index)
{
  if ((index < 0) || (index > m_size))
  {
    throw "Index out of bounds";
  }
  for (int i = index; i < m_size - 1; i++)
  {
    m_list[i] = m_list[i+ 1];
  }
  m_list[m_size -1] = "";
  m_size = m_size - 1;
}


struct Node{
  string key;
  Node *next; //contains the address of the next Node created 
}

class SLL{
  private:
    Node *head, *tail;
  public:
    SLL();
    ~SLL();
    
    Node *search(string sKey);
    //sKey parameter is a string type
    
    void appendNode(string newItem);
}








//Online examples for lists and their functions

//inserting at the start
 void insert_start(int value)
  {
    node *temp=new node;
    temp->data=value;
    temp->next=head;
    head=temp;
  }
  
//inserting at a certain position
  void insert_position(int pos, int value)
  {
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=head;
    for(int i=1;i<pos;i++)
    {
      pre=cur;
      cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;	
    temp->next=cur;
  }
  
//deleting at the start
  void delete_first()
  {
    node *temp=new node;
    temp=head;
    head=head->next;
    delete temp;
  }

//deleting at the end
  void delete_last()
  {
    node *current=new node;
    node *previous=new node;
    current=head;
    while(current->next!=NULL)
    {
      previous=current;
      current=current->next;	
    }
    tail=previous;
    previous->next=NULL;
    delete current;
  }
  
//deleting at a particular position
void delete_position(int pos)
  {
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;
  }