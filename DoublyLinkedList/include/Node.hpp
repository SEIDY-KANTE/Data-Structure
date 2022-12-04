#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

template<typename Object>
struct Node{
    Object data;
    Node<Object>* prev;
    Node<Object>* next;
    Node(const Object& data, Node<Object>*next=NULL, Node<Object>*prev=NULL){
        this->data=data;
        this->prev=prev;
        this->next=next;
    }
};


#endif