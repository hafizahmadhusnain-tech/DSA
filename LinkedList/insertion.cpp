#include <iostream>
using namespace std;

int main(){

    int arr[10] = {1,2,3,4,6};
    int size = 5;
    for(int i = 0; i< size ;i++){

        if (arr[i]>4){
            for ( int j = size;j>i;j--){
                arr[j] = arr[j-1];
            }

            arr[i] = 5;
            size++;
            break;

        }
    }


    for (int k = 0;k<size;k++){
        cout << arr[k] << " ";
    }


    return 0;
}

