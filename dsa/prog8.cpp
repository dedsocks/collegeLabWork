#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
void inputArray(vector<T> &arr){
    int noe; //number of elements
    cout << "Enter the number of elements of array : ";
    cin >> noe;
    arr.resize(noe);

    for(int i = 0; i < noe; i++){
        cout << "Enter the " << i + 1 << " Element : ";
        cin >> arr[i];
    }
}

template<typename T>
void display(vector<T> &arr){
    cout<<endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << "\t";
    }
}

template<typename T>
vector<T> bubbleSort(vector<T> &arr){
    vector<T> sortedArr = arr;
    for(int i = 0; i < sortedArr.size() - 1; i++){
        for(int j = 1; j < sortedArr.size() - i; j++){
            if(sortedArr[j-1] > sortedArr[j]){
                swap(sortedArr[j-1],sortedArr[j]);
            }
        }
    }
    return sortedArr;
}

void displayMenu(){
    cout << "\nSORTING OPTIONS:\n";
    cout << "1.insertion sort\n";
    cout << "2.bubble sort\n";
    cout << "3.selection sort\n";
    cout << "4.exit program\n";
    cout << "Enter your choice: ";
}

int main(){
    vector<int> arr;
    vector<int> sortedArr;
    int choice;

    do{
        displayMenu();
        cin >> choice;

        cout << "\nEnter an array : \n";
        inputArray(arr);

        switch(choice){
            case 1:
                cout << "bon";
                break;
            case 2:
                sortedArr = bubbleSort(arr);
                display(sortedArr);
                break;
            case 3:
                cout << "bim";
                break;
            default:
                break;
        }

    }while(choice != 4);
    

    display(sortedArr);

    return 0;
}

