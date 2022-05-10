#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n; cin >> n;
    string str;
    stack<char> stk;
    pair<char, char> small;
    small.first = '(';
    small.second = ')';

    bool flag;

    for(int i=0; i<n; ++i){
        cin >> str;
        flag = true;


        for(char c : str){
            if(c == small.second){
                if(stk.empty() || stk.top()==small.second){
                    flag = false;
                    break;
                }
                else{ // empty가 아니고 stk top이 small. first인 경우
                    stk.pop();
                }
            }
            else{
                stk.push(c);
            }
        }

        if(!stk.empty()){
            flag = false;
            while(!stk.empty()){
                stk.pop();
            }
        }
        if(flag == true){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}


        // if(!stk.empty() && stk.)
