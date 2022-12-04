#ifndef CIRCULARDOUBLYLINKEDLIST_HPP
#define CIRCULARDOUBLYLINKEDLIST_HPP
#include "Node.hpp"
#include <string>
using namespace std;

template<typename Object>
class CircularDoublyLinkedList{
    private:
        Node<Object>* head;
        int size;
        Node<Object>*FindPrevByPosition(int index){
            if(index<0 || index>size) throw "Error";

            Node<Object>* iterator=head;
            int position=1;
            while(index!=position++){
                iterator=iterator->next;
            }
            return iterator;
        }
    public:
        CircularDoublyLinkedList(){
            head=NULL;
            size=0;
        }
        bool isEmpty(){
            return size==0;
        }
        int Count(){
            return size;
        }
        void add(const Object& item){
            insert(size,item);
        }
        void insert(int index, const Object& item){
         
            if(index==0){
                
                if(size==0){
                    head=new Node<Object>(item);
                    head->next=head;
                    head->prev=head;
                }
                else{
                    head=new Node<Object>(item,head,head->prev);
                    head->next->prev=head;
                    head->prev->next=head;
                }

            }
            else{
                Node<Object>* prevCurrent=FindPrevByPosition(index);
                prevCurrent->next=new Node<Object>(item,prevCurrent->next,prevCurrent);
                prevCurrent->next->next->prev=prevCurrent->next;
            }
            size++;
          
        }
        const Object& first()const{
            return head->data;
        }
        const Object& last(){
            return head->prev->data;
        }
        int indexOf(const Object& item){
            Node<Object>* itr=head;
            int index=0;
            while(size!=index){
                if(itr->data==item) return index;
                itr=itr->next;
                index++;
            }
            throw "Error";
        }
        const Object& elementAt(int index){
            return FindPrevByPosition(index+1)->data;
        }
        bool find(const Object& item){
             Node<Object>* itr=head;
            int index=0;
            while(size!=index++){
                if(itr->data==item) return true;
                itr=itr->next;
            }
            return false;
        }
        void remove(const Object& item){
            int index=indexOf(item);
            removeAt(index);
        }
        void removeAt(int index){
            Node<Object>*del=FindPrevByPosition(index+1);
            del->prev->next=del->next;
            del->next->prev=del->prev;
            if(index==0) head=del->next;
            delete del;
            size--;
        }
        friend ostream& operator<<(ostream& print, CircularDoublyLinkedList<Object>& right){
            Node<Object>* current=right.head;
            int index=0;
            print<<"<-> ";
            while(right.size!=index++){
                print<<current->data<<" <-> ";
                current=current->next;
            }
            print<<endl;

            return print;
        }
        void printNodeFromPositionInReverseOrder(int index){
            Node<Object>* current=FindPrevByPosition(index+1);
            int idx=0;
            cout<<"<-> ";
            while(size!=idx++){
                cout<<current->data<<" <-> ";
                current=current->prev;
            }
            cout<<endl;
        }
        void printNodeFromPositionInOrder(int index){
            Node<Object>* current=FindPrevByPosition(index+1);
            int idx=0;
            cout<<" <-> ";
            while(size!=idx++){
                cout<<current->data<<" <-> ";
                current=current->next;
            }
            cout<<endl;
        }
        void printReverseOrder(){
            printNodeFromPositionInReverseOrder(size-1);
        }
        void clear(){
            while(Count()!=0) removeAt(0);
        }

        ~CircularDoublyLinkedList(){
            clear();
        }

};

#endif