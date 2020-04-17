/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    head = nullptr;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
    bool checker;
    if (head == nullptr){
        checker = true;
    }
    else{
        checker = false;
    }
    return checker;
}

/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
  if (previous==NULL){ //assume that if afterMe is an empty string, the node is made the head
  Country *temp = new Country; //create node
  temp -> name = countryName; //put correct value in
  temp -> next = head; //point it to head
  head = temp; //update the head so it points to temp
  temp = nullptr;
  cout << "adding: " << countryName << " (HEAD)" << endl;
  }
  else{
    //Country *last = search(previous->name); //check if search is in there
    // if (last==nullptr){
    //   cout << "node not found, new node not inserted" << endl; //if you can't find, error message
    // }

    if(previous -> next == nullptr){ //after me is the tail

        else{ //more than 1 Country
        Country *temp = new Country;
        temp->name=countryName;
        temp->next=previous->next;
        previous->next = temp;
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
        }
    }
    else{ //last case (4) you found node and have pointer; it is head or somewhere in the middle 
      Country *temp = new Country;
      temp -> name = countryName;
      temp -> next = previous -> next;
      previous -> next = temp;
      temp = nullptr;
      cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
    }
    
  }

}

/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName)
{
    //three cases of head tail and middle
  Country *tmp;
  if(head->name == countryName){ //if the sKey is in the head
    tmp = head;
    head = tmp->next;
    delete tmp;
    tmp = nullptr;
  }
  else{ 
    bool found = false;
    Country *last = head;
    tmp = head->next; //pointer advancing ahead
    while(!found && tmp!=nullptr){ //while you haven't found it and you haven't reached the tail
      if(tmp->name==countryName){
        found = true;
      }
      else{
        last = tmp; //move to the next one
        tmp = tmp->next;
      }
    }
    if(found){
      if (tmp->next == nullptr){ //if what you found is a tail pointer
        last->next = nullptr;
        //tail = last; //update the tail
      }
      else{ //this is the middle case (dont need to update the tail pointer)
        last->next = tmp->next;
      }
      delete tmp; //deallocate the tmp
      tmp = nullptr;
      last = nullptr; //last is your new tail now 
    }
    else{
        cout << "Country does not exist." << endl;
    }
  }

}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    Country *tmp1;
    while (head!=NULL){
        tmp1 = head;
        cout << "deleting: " << tmp1->name << endl;
        head=tmp1->next;
        delete tmp1;
        tmp1 = nullptr;
    }
    //cout << "Deleted network" << endl;
    head = NULL;
    //cout << "Deleted network" << endl;
    
    string countryArray[6] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    Country *previous = new Country;
    Country *tmp;

   
    for (int i = 0; i < 6; i++){
        if (i == 0){
            previous->name="";
            insertCountry(previous, countryArray[i]);
        }
        else{
            tmp = searchNetwork(countryArray[i - 1]);
            previous = tmp;
            //previous->name=countryArray[i - 1];
            insertCountry(previous, countryArray[i]);
        } 

    }
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName){
    Country *returnCountry = nullptr;
    Country *tmp = head;
    
    bool found = false;
    
    while (!found && tmp!= nullptr){
        if (tmp->name==countryName){
            found = true;
            returnCountry = tmp; //just returning the address
        }
        else{
            tmp = tmp -> next; //otherwise continue to traverse
        }

    }
    return returnCountry; //if nothing is ever found then nullptr is returned
}

/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    Country *tmp;
    while (head!=NULL){
        tmp = head;
        cout << "deleting: " << tmp->name << endl;
        head=tmp->next;
        delete tmp;
        tmp = nullptr;
    }
    
    //cout << "Deleted network" << endl;
    head = NULL;
  
}


/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork()
{
    Country *current = head;
    Country *previous = nullptr;
    Country *next = nullptr;
    
    while (current != nullptr)
    {
        //store the next value
        next = current->next;
        //reverse the current country's pointer
        current->next = previous;
        //move pointers to the next position ahead
        previous = current;
        current = next;
    }
    head = previous;

}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string msg)
{ 
    Country *tmp = head;
    bool found = false;
    
    while (found != true){
        if (tmp == nullptr){ //if the list is empty print "Empty list" (correct?)
            cout << "Empty list" << endl;
            exit(0);
        }
        else if (tmp->name==receiver){
            found = true;
            tmp->numberMessages = tmp->numberMessages + 1;
            tmp->message = msg;
            cout << tmp->name << " [# messages received: " << tmp->numberMessages << "] received: " << tmp->message << endl;
        }
        else{
            
            tmp->message = msg  ;
            tmp->numberMessages = tmp->numberMessages + 1;
            cout << tmp->name << " [# messages received: " << tmp->numberMessages << "] received: " << tmp->message << endl;
            tmp = tmp -> next; //otherwise continue to traverse
        }
    } 
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    Country *tmp = head;
    if (head == nullptr){
        cout << "nothing in path" << endl;
        
    }
    else{
        while (tmp != nullptr){
            cout << tmp->name << " -> ";
            tmp=tmp->next;
        }
        if (tmp == nullptr){
            cout << "NULL" << endl;
        }
        
    }
    
}