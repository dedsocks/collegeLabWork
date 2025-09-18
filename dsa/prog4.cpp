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

	void addAtBeginning(int value){
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		newNode->previos = NULL;
		head = newNode;
		cout << "Element " << value << " Added at Beginning"<<endl;
	}

	/*void addAtEnd(int value){
		Node<T>* temp;
		temp = head;
		Node<T>* newNode = new Node<T>(value);
		newNode->next = NULL;

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		cout << "Element " << value << " Added at End"<<endl;
	}

	void displayList(){
		if(!(checkIfListEmpty())){
			Node* temp;
			temp = head;

			cout << temp->data;
			while(temp->next != NULL){
				temp = temp->next;
				cout << " -> " << temp->data; 
			}
		}
	}

	void deleteAtBeginning(){
		if(!(checkIfListEmpty())){
			Node* temp = head;
			head = head->next;
			cout << temp->data << " has been deleted from the list";
			delete temp;
		}
	}

	void deleteAtEnd(){
		if(!(checkIfListEmpty())){
			Node* temp1 = head;
			Node* temp2 = head;
			while(temp1->next != NULL){
				temp2 = temp1;
				temp1 = temp1->next;
			}
			temp2->next = NULL;
			cout << temp1->data << " has been deleted from the list";
			delete temp1;		
		}
	}

	void searchByKey(int key){
			Node* temp = head;
			int counter = 0;
			int elementFound = 0;

			while(temp->next != NULL){
				if(temp->data == key){
					cout << "Element found at position " << counter + 1;
					elementFound = 1;
					break;
				}
				counter++;
				temp = temp->next;
			}
			if(!elementFound){
				cout << "Element is not present in the list" << endl;
			}
			
	}

	void reverseList(){
		Node* previousNode = head;
		Node* currentNode = previousNode->next;
		Node* nextNode = currentNode->next;

		while(nextNode->next != NULL){
			currentNode->next = previousNode;
			previousNode = currentNode;
			currentNode = nextNode;
			nextNode = nextNode->next;
		}
		nextNode->next = currentNode;
		currentNode->next = previousNode;
		head->next = NULL;
		head = nextNode;
	}*/
};
