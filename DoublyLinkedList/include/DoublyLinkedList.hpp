#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "Node.hpp"

template<typename Object>
class DoublyLinkedList{
    private:
        Node<Object>* head;
        int size;
        Node<Object>* FindPrevByPosition(int position){
            Node<Object>*iterator=head;
            int index=1;
            while(iterator!=NULL && position!=index++){
                iterator=iterator->next;
            }
            return iterator;
        }
    public:

        DoublyLinkedList(){
            head=NULL;
            
            size=0;
        }
        bool isEmpty(){
            return head==NULL;
        }
        int Count(){
            return size;
        }
        void add(const Object& item){
            insert(size,item);
        }
        void insert(int index, const Object& item){
            if(index==0){

                head=new Node<Object>(item,head);
                if(head->next!=NULL) 
                    head->next->prev=head;
            }
            else{
                Node<Object>*current=FindPrevByPosition(index);
                Node<Object>*tmp;
                tmp= new Node<Object>(item,current->next,current);
                current->next=tmp;
                if(index!=size) // if(current->next->next!=NULL)
                    current->next->next->prev=tmp;
            }
           

            size++;
        }
        const Object& first()const{
            return head->data;
        }
        const Object& last(){
            return FindPrevByPosition(size)->data;
        }
        int indexOf(const Object& item){
            Node<Object>*iterator=head;
            int index=0;
            while(iterator!=NULL && index!=size){
                if(iterator->data==item) return index;
                index++;
                iterator=iterator->next;
            }
            throw "Error";
        }
        const Object& elementAt(int index){
            if(index==0) return head->data;
            return FindPrevByPosition(index)->next->data;
        }
        bool find(const Object& item){
            Node<Object>*iterator=head;
            int index=0;
            while(iterator!=NULL && size!=index++){
                if(iterator->data==item) return true;
                iterator=iterator->next;
            }
            return false;
        }
        void remove(const Object& item){
            int index=indexOf(item);
            removeAt(index);
        }
        void removeAt(int index){
            Node<Object>*del;
            if(index==0){
                del=head;
                head=del->next;
                if(head!=NULL)
                    head->prev=del->prev;
                delete del;
            }
            else{
                //first method
                del=FindPrevByPosition(index)->next;
                del->prev->next=del->next;
                if(del->next!=NULL)
                del->next->prev=del->prev;
                delete del;

                //second method
               /* Node<Object>*prv=FindPrevByPosition(index);
                del=prv->next;
                prv->next=del->next;
                if(del->next!=NULL)
                    del->next->prev=prv;
                delete del;
                */

            }
            size--;
        }
        friend ostream& operator<<(ostream& print , DoublyLinkedList<Object>& right){
            Node<Object>*iterator=right.head;
            while(iterator!=NULL){
                print<<iterator->data<<" <-> ";
                iterator=iterator->next;
            }
            print<<endl;

            return print;
        }
        
        void printNodeFromPositionInReverseOrder(int index){
            printNodeFromPositionInOrder(index,"prev");
        }
        void printReverseOrder(){
            printNodeFromPositionInReverseOrder(size-1);
        }
        void printNodeFromPositionInOrder(int index, string direction="next"){
            //if(index<0 || index>size) throw "Error";
            Node<Object>*iterator;
            if(index==0)
                iterator=head;
            else
                iterator=FindPrevByPosition(index+1);

            if(direction=="prev"){
                 while(iterator!=NULL){
                    cout<<iterator->data<<" <-> ";
                    iterator=iterator->prev;
                }
                cout<<endl;
            }
            else{
                 while(iterator!=NULL){
                    cout<<iterator->data<<" <-> ";
                    iterator=iterator->next;
                }
                cout<<endl;
            }
        }
        void clear(){
            while(!isEmpty())
                removeAt(0);
        }
        ~DoublyLinkedList(){
            clear();
        }
};

#endif