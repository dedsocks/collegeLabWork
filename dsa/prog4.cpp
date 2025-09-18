#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
	T data;
	Node* next;
	Node* previos;

	Node(T value){
		data = value;
		Node<T>* next = NULL;
		Node<T>* previos = NULL;
	}
};

template<typename T>
class linkedList{
	Node<T>* head;
public:
	linkedList(){
		head = NULL;
	}
	
	bool checkIfListEmpty(){
	if(head == NULL){
			cout << "List is empty" << endl;
			return 1;
		}
	else return 0;
	}

	void displayList(){
		if(!(checkIfListEmpty())){
			Node<T>* temp;
			temp = head;

			cout << temp->data;
			while(temp->next != NULL){
				temp = temp->next;
				cout << " -> " << temp->data; 
			}
		}
	}

	void addAtBeginning(int value){
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		newNode->previos = NULL;
		if(head != NULL){
			head->previos = newNode;
		}
		head = newNode;
		cout << "Element " << value << " Added at Beginning"<<endl;
	}

	void addAtEnd(int value){
		Node<T>* temp;
		temp = head;
		Node<T>* newNode = new Node<T>(value);

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->previos = temp;
		cout << "Element " << value << " Added at End"<<endl;
	}

};


void displayMainMenu(){
	cout << "\n\n====================== LINKED LIST OPERATIONS ===========================\n\n";
	cout << "1.ADD AT BEGINNING" << endl;
	cout << "2.ADD AT END" << endl;
	cout << "3.DELETE AT BEGINNING" << endl;
	cout << "4.DELETE AT END" << endl;
	cout << "5.DISPLAY LIST" << endl;
	cout << "6.SEARCH BASED ON KEY" << endl;
	cout << "7.REVERSE" << endl;
	cout << "8.EXIT PROGRAM";
	cout << "\n\n=========================================================================\n";
	cout << "Enter your choice : ";
}

int main(){
	linkedList<int> list;
	int choice;
	int userInput;
	
	do{
		displayMainMenu();
		cin >> choice;

		switch(choice){
		case 1:
			cout << "Enter element to add at beginning : ";
			cin >> userInput;
			list.addAtBeginning(userInput);
			break;
		case 2:
			cout << "Enter element to the end : ";
			cin >> userInput;
			list.addAtEnd(userInput);
			break;
		case 5:
			cout << "Current list:\n";
			list.displayList();
			break;
		default:
			cout << "Entered wrong choice\n\n";
		}
	}while(choice != 8);

	return 0;
}
