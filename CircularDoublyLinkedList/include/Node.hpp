#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>

template<typename Object>

struct Node{
    Object data;
    Node<Object>* next;
    Node<Object>* prev;

    Node(const Object& data, Node<Object>*next=NULL, Node<Object>*prev=NULL){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }    
};


#endif