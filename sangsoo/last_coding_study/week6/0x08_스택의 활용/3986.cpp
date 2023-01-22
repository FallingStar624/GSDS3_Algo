#include <iostream>
#include <stack>
#include <string>

using namespace std;

void printstk(stack<char> stk){
    for(int i = 0; i < stk.size();i++){
        cout << stk.top()<< " ";
        stk.pop();
    }
    cout << '\n';
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    int output =0;
    cin >> N;
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;
        stack<char> stk;
        for (int j = 0; j < str.length(); j++){
            if(stk.empty()){stk.push(str[j]);}
            else{
                if(str[j]==stk.top()){stk.pop();}
                else{stk.push(str[j]);}
            }
        }
        if(stk.empty()) output += 1;
        while(!stk.empty()){stk.pop();}
    }
    cout << output;
}