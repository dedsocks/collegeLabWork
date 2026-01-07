#include<iostream>
#include<vector>
using namespace std;

void inputHashValue(vector<int> &arr){
    int key, index;
    cout << "\nEnter the value to insert into the hashtable : ";
    cin >> key;
    index = key%arr.size();
    for(int i = 0; i < arr.size(); i++){
        if(arr[index] == -1){
            arr[index] = key;
            return;
        }
        index = (index + 1)%arr.size();
    }
    cout << "\nHash Table is full\n";
}

void display(vector<int> &arr){
    cout << "\n";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << "\t";
    }
}

// ht => hash table 
void createHashTable(vector<int> &ht){
    int ht_size;
    cout << "\nEnter size of the hashtable : ";
    cin >> ht_size;
    for(int i = 0; i < ht_size; i++){
        ht.push_back(-1);
    }   
    return;
}

void displayMenu(){
    cout << "\nHASH TABLE OPERATIONS" << endl;
    cout << "1.Input Value" << endl;
    cout << "2.Display" << endl;
    cout << "3.Exit" << endl;
    cout << "Enter your choice : ";
}

int main(){
    vector<int> hashTable;
    int choice = 0;

    createHashTable(hashTable);

    do{
        displayMenu();
        cin >> choice;
        
        if(choice == 1){
            inputHashValue(hashTable);
        }
        else if(choice == 2){
            display(hashTable);
        }
            
    }while(choice != 3);

    return 0;
}