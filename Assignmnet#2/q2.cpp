#include <iostream>
#include <stack>
#include <string>
using namespace std;
int prec(char c){
    if (c=='^') return 3;
    else if (c=='*' || c=='/') return 2;
    else if (c=='+' || c=='-') return 1;
    else return 0;
}
string postFix(string str){
    string res = "";
    stack<char> s;
    for (int i = 0;i<str.length();i++){
        if(str[i]==' ')continue;
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
            res+=str[i];
        }
        else if(str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            while(!s.empty() && s.top()!='('){
                res+=s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && prec(str[i])<prec(s.top())){
                res+=s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        res+=s.top();
        s.pop();
    }
    return res;
}
int main(){
    cout << postFix("(A^F * Z) / X (Y + Z)") << endl;
    return 0;
}