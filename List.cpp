#include "List.h"
#include <iostream>
#include <stdexcept>//used to be able to "throw" exceptions

using namespace std;


class List::Node //self-referential Node class
{
	public:
	   int data = 0;
	   Node* link = nullptr;
	   //link is a data member which is a pointer 
	   //to an object of the same type (i.e. Node)
	
	};//end Node class definition (can only be seen by the List class)


List::~List()
{
    while(num_elements > 0)
      remove(1);
}
	
int List::size()
 {
    return num_elements;
 }

void List::insert(int val, int k)
{
	if (k < 1 or k > num_elements +1) //if the location is invalid
	     throw out_of_range("List::insert("+to_string(val)+", " +to_string(k)+") failed. (valid indices are 1 to "+to_string(num_elements+1)+")");//throw an "out_of_range" exception
	
	
	Node* newPtr = new Node{val};
	
	if(k == 1)
	{
	  newPtr->link = frontPtr;
	  frontPtr = newPtr;
	 }
	else
	 {  
	
	  Node* tmpPtr = frontPtr;
	  int loc = 1; 
	  
	    while( loc != k-1) //get pointer to (k-1)th node
	     {
		tmpPtr = tmpPtr->link;
		loc++;
	     }
	
	  newPtr->link = tmpPtr->link;
	  tmpPtr->link = newPtr;  
        }//end else

     num_elements++;
 }

void List::remove(int k)
{
	if (k < 1 or k > num_elements)//if the location is invalid 
	     throw out_of_range("List::remove(" +to_string(k)+") failed. (valid indices are 1 to "+to_string(num_elements)+")");//throw an "out_of_range" exception
	
	Node* delPtr;
	
	if(k == 1)
	{
	  delPtr = frontPtr;
	  frontPtr = frontPtr->link;
	 }
	 else
	 {
	    Node* tmpPtr = frontPtr;
		
	    int loc = 1;
            
            while(loc != k-1)//get pointer to (k-1)th node
	    {
	       tmpPtr = tmpPtr->link;
		loc++;
	    }
	
	    delPtr = tmpPtr->link;
	    tmpPtr->link = delPtr->link;
	  }
	
	delete delPtr;
	num_elements--;
	}
	
	//Implementations of missing operations

bool List::isEmpty() {
	return num_elements == 0;
}

void List::clear() {
	while(!isEmpty())
		remove(1);
}

int List::get(int k) {
	if (k < 1 or k > num_elements)//if the location is invalid 
	     throw out_of_range("List::remove(" +to_string(k)+") failed. (valid indices are 1 to "+to_string(num_elements)+")");//throw an "out_of_range" exception
	
	Node* getPtr;
	
	getPtr = frontPtr;
	if(k != 1)
	 	for(int i = 0; i < k - 1; i++)
	 		getPtr = getPtr->link;
	return getPtr->data;
}

void List::display() {
	Node *curPtr = frontPtr;
	for(int i = 0; i < size(); i++) {
		cout<<curPtr->data<<" ";
		curPtr = curPtr->link;
	} 
	cout<<endl;
}
