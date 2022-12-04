#ifndef BST_HPP
#define BST_HPP

#include<iostream>
#include<cmath>
using namespace std;

template<typename Object>
struct Node{

	Object data;
	Node<Object>* left;
	Node<Object>* right;

	Node(const Object& data, Node<Object>*left=NULL, Node<Object>*right=NULL){
		this->data=data;
		this->left=left;
		this->right=right;
	}

};

template<typename Object>
class BST{
    private:
       Node<Object>* root;
        void searchAndAdd(Node<Object>*&subNode,const Object& item){
			if(subNode==NULL) subNode=new Node<Object>(item);
			else if(item<subNode->data)
				searchAndAdd(subNode->left,item);
			else if(item>subNode->data)
				searchAndAdd(subNode->right,item);
			else return;
		}
		bool searchAndDelete(Node<Object>*&subNode, const Object& item){
			if(subNode==NULL) return false;
			else if(item<subNode->data)
				return searchAndDelete(subNode->left,item);
			else if(item>subNode->data)
				return searchAndDelete(subNode->right,item);
			else
				return deleteNode(subNode);
				
			 
		}
		bool deleteNode(Node<Object>*&subNode){
			Node<Object>* delNode=subNode;
			if(subNode->left==NULL) subNode=subNode->right;
			else if(subNode->right==NULL) subNode=subNode->left;
			else{
				delNode=subNode->right;
				Node<Object>* parent=subNode;
				while(delNode->left!=NULL){
					parent=delNode;
					delNode=delNode->left;
				}
				subNode->data=delNode->data;
				if(parent==subNode) subNode->right=delNode->right;
				else parent->left=delNode->right;
			}
			delete delNode;
			return true;
		}
		void inorder(Node<Object>*subNode){
			if(subNode!=NULL){
				inorder(subNode->left);
				cout<<subNode->data<<" ";
				inorder(subNode->right);
			}	
		}
		void preorder(Node<Object>*subNode){
			if(subNode!=NULL){
				cout<<subNode->data<<" ";
				preorder(subNode->left);
				preorder(subNode->right);
			}	
		}
		void postorder(Node<Object>*subNode){
			if(subNode!=NULL){
				postorder(subNode->left);
				postorder(subNode->right);
				cout<<subNode->data<<" ";
			}	
		}
		void levelorder(Node<Object>*subNode,int level){
			if(subNode==NULL) return;
			if(level==0) cout<<subNode->data<<" ";
			else{
				levelorder(subNode->left,level-1);
				levelorder(subNode->right,level-1);
			}
		}
		int Height(Node<Object>*subNode){
			if(subNode==NULL) return -1;
			return 1+max(Height(subNode->left),Height(subNode->right));
		}

		bool search(Node<Object>*subNode, const Object& item){
			if(subNode==NULL) return false;
			else if(item==subNode->data) return true;
			else if(item<subNode->data)
				return search(subNode->left,item);
			else
				return search(subNode->right,item);
		}
		 
    public:

		BST(){
			root=NULL;
		}
		bool isEmpty(){
			return root==NULL;
		}
		void add(const Object& item){
			searchAndAdd(root,item);
		}
		void Delete(const Object& item){
			if(searchAndDelete(root,item)==false) throw "item not found";
		}
		void inorder(){
			inorder(root);
		}
		void preorder(){
			preorder(root);
		}
		void postorder(){
			postorder(root);
		}
		void levelorder(){
			int h=Height();
			for(int level=0; level<h; level++){
				levelorder(root,level);
			}
		}
		int Height(){
			return Height(root);
		}
		bool find(const Object& item){
			return search(root,item);
		}
		void clear(){
			while(!isEmpty()) deleteNode(root);
				//Delete(root->data);
		}
		~BST(){
			clear();
		}
};

#endif