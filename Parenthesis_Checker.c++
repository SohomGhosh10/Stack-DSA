#include<iostream>
using namespace std;
#include<stack>

bool checkValid(char open , char close){
    if(open == '(' && close == ')' || open == '{' && close == '}' || open == '[' && close == ']'){
        return true;
    }else{
        return false;
    }
}

bool checkBalance(string exp){
    stack<char> s;
    for(char ch : exp){
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }else if(ch == ')' || ch == '}' || ch == ']'){
            if(s.empty() || !checkValid(s.top() , ch)){
                return false;
            }else{
                s.pop();
            }
        }
    }
    return s.empty() ? true : false;

}

int main(){
    string exp;
    getline(cin , exp);

    if(checkBalance(exp)){
        cout << "Balanced" << endl;
    }else{
        cout << "Unbalanced" << endl;
    }
}