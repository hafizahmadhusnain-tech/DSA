#include <iostream>
#include <string>
#include <stack>
using namespace std;
int prec(char c){
    if (c=='^') return 3;
    else if (c=='*' || c=='/') return 2;
    else if (c=='+' || c=='-') return 1;
    else return -1;   
}

string postFix(string exp){
    stack<char> s;
    string res="";
    for(int i=0;i<exp.length();i++){
        if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z'){
            res+=exp[i];
        }
        else if (exp[i]=='('){
            s.push(exp[i]);
        }
        else if (exp[i]==')'){
            while(!s.empty() && s.top()!='('){
                res+=s.top();
                s.pop();
            }
            s.pop();    
        }
        else{
            while (!s.empty() && prec(s.top())>prec(exp[i])){
                res+=s.top();
                s.pop();
            }
            s.push(exp[i]);                 
        }
    }
    while(!s.empty()){
        res+=s.top();
        s.pop();
    }
    return res;
}

int main(){

    cout<< postFix("A+(B*C)/D*E");

    return 0;
}