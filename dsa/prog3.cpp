#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int value){
		data = value;
		Node* next = NULL;
	}
};

class linkedList{
	Node* head;
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
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		cout << "Element " << value << " Added at Beginning"<<endl;
	}

	void addAtEnd(int value){
		Node* temp;
		temp = head;
		Node* newNode = new Node(value);
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
	linkedList list;
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
		case 3:
			list.deleteAtBeginning();
			break;
		case 4:
			list.deleteAtEnd();
			break;
		case 5:
			cout << "Current list:\n";
			list.displayList();
			break;
		case 6:
			if(!(list.checkIfListEmpty())){
				cout << "Enter the key to search : ";
				cin >> userInput;
				list.searchByKey(userInput);
			}
			break;
		case 7:
			break;
		case 8:
			cout << "Exiting from program ...";
			break;
		default:
			cout << "Entered wrong choice\n\n";
		}
	}while(choice != 8);

	return 0;
}



