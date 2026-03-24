#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isBalanced(string exp){
    int n = exp.length();
    stack<char> s;
    for(int i = 0;i<n;i++){
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            s.push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(s.empty()){
                return false;
            }
            if (exp[i]==')' && s.top()=='('||
                exp[i]=='}' && s.top()=='{'||
                exp[i]==']' && s.top()=='['){
                    s.pop();
                }
                else{
                    return false;}
        }
    }
    return s.empty();
}
int main(){
    if(isBalanced("[{(){[}]}}]")){
    cout << "Balanced!";
}
    else{
    cout << "Unbalanced!";}

    return 0;
}