#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    stack<string> s;
    string input;
    int choice;
    while(true){
        cout << "1.Operations\n2.Undo\n3.Exit\nchoice: ";
        cin>>choice;
        cin.ignore();
        switch (choice){
        case 1:
            cout << "Enter action(insert/delete/change font): ";
            getline(cin,input);
            s.push(input);
            cout << "Action Performed: " << input <<endl;
            break;
        case 2:
        if(!s.empty()){
            cout <<"Action Undo: " <<s.top()<<endl;
            s.pop();
        }
        else{
            cout <<"Noting to Undo!\n";
        }
            break;
        case 3:
        return 0;
            break;    
        default:
            cout << "invalid Input!\n";
            break;
        }
    }
} 