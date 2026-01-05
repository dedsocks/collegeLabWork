#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void inputArray(vector<T> &arr){
    int noe; //number of elements
    cout << "Enter the number of elements of array : ";
    cin >> noe;

    for(int i = 0; i < noe; i++){
        cout << "Enter the " << i + 1 << " Element : "
        cin >> arr[i];
    }
}

template<typename T>
void display(vector<T> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << "\t";
    }
}

template<typename T>
int main(){
    vector<T> arr;
    int choice;

    cout << "Enter an array : ";
    inputArray(arr);
}