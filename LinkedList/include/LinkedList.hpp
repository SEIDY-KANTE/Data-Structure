#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"

template<typename Object>

class LinkedList{
	
	private:
		Node<Object>* head;
		int size;
	
	public:
		LinkedList(){
			head = new Node<Object>();
			size=0;
		}
		
};
#endif