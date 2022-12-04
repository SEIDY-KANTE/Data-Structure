#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>

using namespace std;

template<typename Object>
class ArrayList
{

public:

	ArrayList(){
		length=0;
		capacity=100;
		data=new Object[capacity];	
	}
	int size(){
		return length;
	}
	int indexOf(const Object& data){
		for(int i=0; i<size(); i++){
			if(this->data[i]==data)
				return i;
		}
		throw "Error";
	}
	void add(const Object& data){
		insert(size(), data);
	}
	void insert(int index, const Object& data ){
		if(size()==capacity) reserve(2*capacity);

		if(index<0 || index>size()) throw "Error";

		for(int i=size(); i>index; i--){
			this->data[i]=this->data[i-1];
		}
		this->data[index]=data;
		length++;
	}
	void remove(Object& data){
		int index=indexOf(data);
		removeAt(index);
	}
	void removeAt(int index){
		if(index<0 || index>size()) throw "Error";
		for(int i=index; i<size() ; i++){
			this->data[i]=this->data[i+1];
		}
		length--;
	}
	const Object& first(){
		return data[0];
	}
	const Object& last(){
		return data[size()-1];
	}
	const Object& elementAt(int index){
		return data[index];
	}
	bool isFind(const Object& data){
		for(int i=0; i<size(); i++){
			if(this->data[i]==data)
				return true;
		}
		return false;
	}
	bool isEmpty(){
		return size()==0;
	}

	void clear(){
		length=0;
	}
	friend ostream& operator<<(ostream& print, ArrayList<Object>&right){
		print<<endl;
		for(int i=0; i<right.size(); i++)
			print<<right.data[i]<<" | ";
		print<<endl;
		return print;
	}
	~ArrayList(){
		delete []data;
	}

private:
	Object* data;
	int length;
	int capacity;
	void reserve(int newCapacity){

		Object* temp= new Object[newCapacity];
		for(int i=0; i<size(); i++) 
			temp[i]=data[i];

		delete []data;
		data=temp;
		capacity=newCapacity;
	}
};

#endif