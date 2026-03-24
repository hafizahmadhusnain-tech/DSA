#include <iostream>
using namespace std;

int main(){

    int arr[10] = {1,2,3,4,6};
    int size = 5;
    int key = 4;
    bool isFound = false;
    int index;

    for(int i = 0; i< size ;i++){
        if (arr[i]==key){
            isFound = true;
            index = i;
        }
        
    }

    if (isFound){
        cout << " key found at index: " << index;
    }
    else {
            cout << "Key not found";
        }

    return 0;
}