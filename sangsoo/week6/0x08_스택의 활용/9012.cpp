// if stk is empty and try to use stk.top(), it makes error.
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        string str;
        stack<char> stk;
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            if(str[j] == '(') stk.push(str[j]);
            else if(!stk.empty() && str[j] == ')'){
                if(stk.top() == '(') stk.pop();
                else {stk.push(str[j]);}
            }
            else if(stk.empty() && str[j] == ')'){
                stk.push(str[j]);
            }
        }
        if(stk.empty()) cout<< "YES"<<'\n';
        else cout<< "NO"<<'\n';
    }

}