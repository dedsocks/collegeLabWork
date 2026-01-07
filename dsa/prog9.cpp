#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
template<typename T>

void display(vector<T> &arr){
    cout<<endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << "\t";
    }
}

template<typename T>
void inputArray(vector<T> &arr){
    int noe; //number of elements
    cout << "\nEnter the number of elements of array : \n";
    cin >> noe;
    arr.resize(noe);

    for(int i = 0; i < noe; i++){
        cout << "Enter the " << i + 1 << " Element : ";
        cin >> arr[i];
    }
}

template<typename T>
int partition(vector<T> &arr, T low, T high){
    T pivot = arr[high];
    int i = low - 1;
    int j = low;
    while(j < high){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[high]);
    return i + 1;
}

template<typename T>
void quickSort(vector<T> &arr, int low, int high){
    if (low < high){
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

int main(){
    vector<int> arr;

    cout << "Enter array to perform quicksort";
    inputArray(arr);

    cout <<"\nArray before sorting \n";
    display(arr);

    cout << "\nArray after sorting : \n";
    quickSort(arr, 0, arr.size() - 1);
    display(arr);

    return 0;
}