#include<iostream>
#include "CircularDoublyLinkedList.hpp"

using namespace std;

int main()
{
	CircularDoublyLinkedList<string> *names = new CircularDoublyLinkedList<string>();
	
	string item;
	int index, choice;
	
	do
	{
		system("cls");
		cout<<"*********MENU**************"<<endl;
		cout<<"1 . Add "<<endl;
		cout<<"2 . Insert "<<endl;
		cout<<"3 . Remove "<<endl;
		cout<<"4 . RemoveAt "<<endl;
		cout<<"5 . First "<<endl;
		cout<<"6 . Last "<<endl;
		cout<<"7 . Clear "<<endl;
		cout<<"8 . Size "<<endl;
		cout<<"9 . IsEmpty "<<endl;
		cout<<"10. IndexOf "<<endl;
		cout<<"11. Print "<<endl;
		cout<<"12. ElementAt "<<endl;
		cout<<"13. IsFind "<<endl;
		cout<<"14. printNodeFromPositionInReverseOrder "<<endl;
		cout<<"15. printReverseOrder "<<endl;
        cout<<"16. printNodeFromPositionInOrder "<<endl;
		cout<<"17. Exit "<<endl;
		cout<<"Choice: "; cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Enter the item: ";
				cin.ignore();
				getline(cin,item);
				names->add(item);
				cout<<"Element is added"<<endl;
				cin.get();
			break;
			
			case 2:
				cout<<"Enter the index: ";
				cin>>index;
				cout<<"\nEnter the item: ";
				cin.ignore();
				getline(cin,item);
				names->insert(index,item);
				cout<<"Element is inserted"<<endl;
				cin.get();
			break;
			
			case 3:
				cout<<"\nEnter the item: ";
				cin.ignore();
				getline(cin,item);
				names->remove(item);
				cout<<"Element is removed"<<endl;
				cin.get();
			break;
			
			case 4:
				cout<<"Enter the index: ";
				cin>>index;
				names->removeAt(index);
				cout<<"Element is removed"<<endl;
				cin.get();
			break;
			
			case 5:
				cout<<"First element is: "<<names->first()<<endl;
				cin.ignore();
				cin.get();
			break;
			
			case 6:
				cout<<"Last element is: "<<names->last()<<endl;
				cin.ignore();
				cin.get();
			break;
			
			case 7:
				names->clear();
				cout<<"All element is cleaned.\nNow my ArrayList is empty."<<endl;
				cin.ignore();
				cin.get();
			break;
			
			case 8:
				cout<<"The size of my ArrayList is: "<<names->Count()<<endl;
				cin.ignore();
				cin.get();
			break;
			
			case 9:
				if(names->isEmpty())
					cout<<"My ArrayList is empty"<<endl;
				else
					cout<<"My ArrayList is not empty"<<endl;
				
				cin.ignore();
				cin.get();
			break;
			
			case 10:
				cout<<"\nEnter the item: ";
				cin.ignore();
				getline(cin,item);
	
				cout<<"The index of the element "<<item<<" is "<<
				names->indexOf(item)<<endl;

				cin.get();
			break;
			
			case 11:
				cout<<"************The elements of the list********* "<<endl;
				cout<<*names<<endl;
				cin.ignore();
				cin.get();
			break;
			
			case 12:
				cout<<"Enter the index: ";
				cin>>index;
				
				cout<<"The element of the index "<<index<<" is "<<
				names->elementAt(index)<<endl;
				cin.ignore();
				cin.get();
			break;
			
			case 13:
				cout<<"\nEnter the item: ";
				cin.ignore();
				getline(cin,item);
				if(names->find(item))
					cout<<"Element is found"<<endl;
				else
					cout<<"Element is not found"<<endl;
				
				cin.get();
			break;
			
			case 14:
				cout<<"Enter the index: ";
				cin>>index;
				cout<<"************Print Node From Position In Reverse Order********* "<<endl;
				names->printNodeFromPositionInReverseOrder(index);
				cin.ignore();
				cin.get();
			break;
			
			case 15: 
			cout<<"************Print Reverse Order********* "<<endl;
			names->printReverseOrder();
				cin.ignore();
				cin.get();
			break;
			
			case 16: 
            cout<<"Enter the index: ";
				cin>>index;
				cout<<"************Print Node From Position In Order********* "<<endl;
				names->printNodeFromPositionInOrder(index);
				cin.ignore();
				cin.get();
			
			break;
			case 17:
                exit(0);
            break;
			default:
				cout<<"Error choice"<<endl;
				cin.ignore();
				cin.get();
			break;
		}
		
	}while(choice!=17);
	
	delete names;
	return 0;
}