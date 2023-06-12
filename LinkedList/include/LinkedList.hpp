

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"

template<typename Object>

class LinkedList{
	
	private:
		Node<Object>* head;
		int size;
		Node<Object>* FindPrevByPosition(int position){
			if(position<0 || position>size) throw "Error";
			Node<Object>* current=head;
			int index=0;
			while(current->next!=NULL && position!=index++ ){
				current=current->next;
			}
			return current;
		}
	public:
		LinkedList(){
			head = new Node<Object>();
			size=0;
		}
		bool isEmpty(){
			return size==0;
		}
		int Count()const{
			return size;
		}
		void add(const Object& data){
			insert(Count(),data);
		}
		void insert(int index, const Object& data){
			Node<Object>*current=FindPrevByPosition(index);
			current->next=new Node<Object>(data,current->next);
			size++;
		}
		const Object& first(){
			return head->next->data;
		}
		const Object& last(){
			Node<Object>*current=FindPrevByPosition(Count());
			return current->data;
		}
		int indexOf(Object& item){
			Node<Object>*current=head;
			int index=0;
			while(current->next!=NULL){
				if(current->next->data==item) return index;
				current=current->next;
				index++;
			}
			throw "Error value";
		}
		const Object& elementAt(int index){
			if(index<0 || index>Count()) throw "Error";
			Node<Object>* current=FindPrevByPosition(index);
			return current->next->data;
		}
		bool find(Object& item)const{
			Node<Object>*current=head->next;
			while(current->next!=NULL){
				current=current->next;
				if(current->data==item) return true;
			}
			return false;
		}
		void remove(Object& data){
			int index=indexOf(data);
			removeAt(index);
		}
		void removeAt(int index){
			if(index<0 || index>Count()) throw "Error";
			Node<Object>*prevCurrent=FindPrevByPosition(index);
			Node<Object>*currentDeleted=prevCurrent->next;
			prevCurrent->next=prevCurrent->next->next;
			delete currentDeleted;
			size--;
			
		}
		friend ostream& operator<<(ostream& print, LinkedList<Object>& right){
			Node<Object>*current=right.head;
			print<<endl;
			while(current->next!=NULL){
				print<<current->next->data<<" -> ";
				current=current->next;
			}
			print<<"NULL"<<endl;
			
			return print;
		}
		
		void clear(){
			while(!isEmpty()){
				removeAt(0);
			}
		}
		~LinkedList(){
			clear();
			delete head;
		}
};
#endif
