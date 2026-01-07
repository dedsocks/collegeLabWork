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

template<typename T>
vector<T> insertionSort(vector<T> &arr){
    vector<T> sortedArr = arr;
    for(int i = 0; i < sortedArr.size(); i++){
        int temp = 0;
        for(int j = 0; j < i; j++){
            if(sortedArr[i] < sortedArr[j] || temp != 0){
                flag = 1;
                sortedArr[j+1] = sortedArr[j];
            }
        }
    }
    return sortedArr;
}

template<typename T>
vector<T> selectionSort(vector<T> &arr){
    vector<T> sortedArr = arr;
    int smallest_index;
    for(int i = 0; i < arr.size() - 1; i++){
        smallest_index = i;
        for(int j = i+1; j < arr.size(); j++ ){
            if(sortedArr[j] < sortedArr[smallest_index]){
                smallest_index = j;
            }
        }
        if(smallest_index != i){
            swap(sortedArr[i],sortedArr[smallest_index]);
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
    int choice = 0;

    do{
        displayMenu();
        cin >> choice;

        cout << "\nEnter an array : \n";
        inputArray(arr);

        switch(choice){
            case 1:
                sortedArr = insertionSort(arr);
                display(sortedArr);
                break;
            case 2:
                sortedArr = bubbleSort(arr);
                display(sortedArr);
                break;
            case 3:
                sortedArr = selectionSort(arr);
                display(sortedArr);
                break;
            default:
                break;
        }

    }while(choice != 4);
    

    display(sortedArr);

    return 0;
}

