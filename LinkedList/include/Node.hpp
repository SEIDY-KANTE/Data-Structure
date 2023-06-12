#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;
 
template<typename Object>

struct Node{
	Object data;
	Node<Object>* next;
	
	Node(const Object& data = Object(), Node<Object>*next=NULL){
		this->data=data;
		this->next=next;
	}
	
};


#endif