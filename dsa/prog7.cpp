#include<iostream>
using namespace std;
class Node{
    public:
        int key;
        Node* left;
        Node* right;

        Node(int data){
            key = data;
            left = right = NULL;
        }
};
class BST{
    public:
        Node* root;

        BST(){
            root = NULL;
        }

        int findSmallestElement(Node* root){
            if(root->left == NULL){
                return root->key;
            }
            else{
                return findSmallestElement(root->left);
            }
        }

        int findTreeHeight(Node* root){
            int leftTreeHeight = 1;
            int rightTreeHeight = 1;
            if(root == NULL){
                return 0;
            }
            else if(root->left == NULL && root->right == NULL){
                return 1;
            }
            else{
                leftTreeHeight += findTreeHeight(root->left);
                rightTreeHeight += findTreeHeight(root->right);
                if(leftTreeHeight > rightTreeHeight){
                    return leftTreeHeight ;
                }
                else return rightTreeHeight ;
            }

        }

        Node* insertElement(Node* root, int data){
            if(root == NULL){
                cout << data << " has been inserted into the tree " << endl;
                return new Node(data);
            }
            else if(data > root->key){
                root->right = insertElement(root->right, data);
            }
            else if(data < root->key){
                root->left = insertElement(root->left, data);
            }
            return root;
        }

        bool searchElement(Node* root, int data){
            if(root == NULL){
                return false;
            }
            else{
                if(data > root->key){
                    searchElement(root->right, data);
                }
                else if(data < root->key){
                    searchElement(root->left, data);
                }
                else return true;
            }
        }

        Node* deleteElement(Node* root, int data){
            if(root == NULL){
                return root;
            }
            else {
                if(data > root->key){
                    root->right = deleteElement(root->right, data);
                }
                else if(data < root->key){
                    root->left = deleteElement(root->left, data);
                }
                else{
                    if(root->right == NULL && root->left == NULL){
                        delete root;
                        return NULL;
                    }
                    else if(root->right == NULL || root->left == NULL){
                        Node* temp = (root->left != NULL)?(root->left):(root->right);

                        delete root;
                        return temp;
                    }
                    else {
                        root->key = findSmallestElement(root->right);
                        root->right = deleteElement(root->right, root->key);
                    }
                }
            }
            return root;
        }

        void displayPreorder(Node* root){
            if(root){
                cout << root->key << "\t";
                displayPreorder(root->left);
                displayPreorder(root->right);
            }
        }

        void displayInorder(Node* root){
            if(root){
                displayInorder(root->left);
                cout << root->key << "\t" ;
                displayInorder(root->right);
            }
        }

        void displayPostorder(Node* root){
            if(root){
                displayPostorder(root->left);
                displayPostorder(root->right);
                cout << root->key << "\t" ;
            }
        }
};

void displayMainMenu(){
	cout << "\n\n====================== BST OPERATIONS ===========================\n\n";
	cout << "1.INSERT ELEMENT" << endl;
	cout << "2.DELETE ELEMENT" << endl;
	cout << "3.SEARCH ELEMENT" << endl;
	cout << "4.FIND TREE HEIGHT" << endl;
	cout << "5.INORDER TRAVERSAL" << endl;
	cout << "6.POSTORDER TRAVERSAL" << endl;
	cout << "7.PREORDER TRAVERSAL" << endl;
	cout << "8.EXIT PROGRAM";
	cout << "\n\n=========================================================================\n";
	cout << "Enter your choice : ";
}

int main(){
    BST b1;
    int choice = 0;
    int value;

    do{
    displayMainMenu();
    cin >> choice;
    switch(choice){
        case 1:
            cout << endl;
            cout << "Enter element to insert into BST : ";
            cin >> value;
            b1.root = b1.insertElement(b1.root, value);
            break;
        case 2:
            cout << endl;
            cout << "Elements in the tree : " ;
            b1.displayInorder(b1.root);
            cout << "Enter element to delete from BST : ";
            cin >> value;
            b1.root = b1.deleteElement(b1.root, value);
            cout << value << "has been deleted from the tree";
            break;
        case 3:
            cout << endl;
            cout << "Enter element to search in BST : ";
            cin >> value;
            if(b1.searchElement(b1.root, value)){
                cout << "\nElement is present in tree";
            }
            else cout << "\nElement is not present in tree";
            break;
        case 4:
            cout << endl;
            cout << "Height of BST : " << b1.findTreeHeight(b1.root);
            break;
        case 5:
            cout << endl;
            cout << "Elements in the tree : " ;
            b1.displayInorder(b1.root);
            b1.root = b1.insertElement(b1.root, value);
            break;
        case 6:
            cout << endl;
            cout << "Elements in the tree : " ;
            b1.displayPostorder(b1.root);
            b1.root = b1.insertElement(b1.root, value);
            break;
        case 7:
            cout << endl;
            cout << "Elements in the tree : " ;
            b1.displayPreorder(b1.root);
            b1.root = b1.insertElement(b1.root, value);
            break;
        case 8:
            cout << endl;
            cout << "Exiting program ...";
            break;
        default:
            cout << endl;
            cout << "Enter correct choice";
            break;
    }
    }while(choice != 8);

    return 0;
}