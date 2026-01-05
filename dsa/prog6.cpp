#include<iostream>
#include<string>
#include<vector>
using namespace std;
class deque{
    public:
    vector<char> arr;

    void pushFront(char element){
        arr.push_back(arr[arr.size()-1]);
        for(int i = arr.size() - 1; i >= 2; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = element;   
    }

    void pushBack(char element){
        arr.push_back(element);
    }

    void popFront(){
        arr.erase(arr.begin());
    }

    void popBack(){
        arr.pop_back();
    }

    bool isEmpty(){
        return arr.empty();
    }
};
int main(){
    deque dq;
    string userInput;

    cout << "Enter a string to check if palindrome or not";
    cin >> userInput;

    for(int i = 0; i < userInput.length(); i++){
        dq.pushBack(userInput[i]);
    }

    
}