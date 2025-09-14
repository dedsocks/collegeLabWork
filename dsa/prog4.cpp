#include<iostream>
using namespace std;

template<class T>
class Node{
public:
	T data;
	Node* next;
    Node* previos;

	Node(int value){
		data = value;
		Node* next = NULL;
        Node* previous = NULL;
	}
};