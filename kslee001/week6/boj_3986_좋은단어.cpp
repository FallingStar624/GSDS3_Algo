#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main(){
    int n; cin >>n;
    string str;
    stack<char> stk;

    int num = 0;

    for(int i=0; i<n; ++i){
        cin>> str;
        for(char c: str){
            if(stk.empty()==false && stk.top()== c){
                stk.pop();
            }
            else{
                stk.push(c);
            }
        }

        if(stk.empty()){
            num ++;
        }
        while(!stk.empty()){
            stk.pop();
        }
    }
    cout << num;
}