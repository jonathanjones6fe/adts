#include "StackLL.h"
#include <stdexcept>

class Stack::Node {
	public:
		int data = 0;
	    Node* link = nullptr;
	    
		Node(int val) {
			data = val;
		}	    
};

Stack::~Stack() {
	clear();
}

int Stack::size() {
	return num_elements;
}

void Stack::push(int i) {
	Node* newPtr = new Node(i);
	
	if(num_elements == 0) {
	  newPtr->link = frontPtr; //set head to point to null
	  frontPtr = newPtr; //set new as head
	} else {  
	   Node* curPtr = frontPtr;
	   for(int j = 0; j < num_elements-1; j++)
	   		curPtr = curPtr->link;
	  newPtr->link = curPtr->link; //new element point to null
	  curPtr->link = newPtr; //old top of stack point to new top
     }//end else
     num_elements++;
}

void Stack::pop() {
	Node* delPtr;
	if(num_elements == 1) {
	  delPtr = frontPtr; //prepare head to be erased
	  frontPtr = frontPtr->link; //set head to point to null
	} else {
	    Node* curPtr = frontPtr;
	    for(int i = 1; i < num_elements -1; i++)
	    	curPtr = curPtr->link; //find stack top
	
	    delPtr = curPtr->link; //prepare stack top to be erased
	    curPtr->link = delPtr->link; //top point to null
	 }
	
	delete delPtr;
	num_elements--;
}

int Stack::top() {
	Node *getPtr = frontPtr;
	
	if (num_elements != 1)
		for(int j = 1; j < num_elements; j++) 
			  getPtr = getPtr->link;
	return getPtr->data;
}

void Stack::clear() {
	while(num_elements > 0)
		pop();
}
