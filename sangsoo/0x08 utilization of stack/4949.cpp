#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true){
    string a;
    getline(cin, a);
    if (a == ".") break;
    bool flag = false;
    stack<char> stk;
    for (int i = 0; i < a.length(); i++){
        if ((a[i] == '(') || (a[i] == '[')){
            stk.push(a[i]);
        }
        else if (a[i] == ')'){
            if (!stk.empty() && stk.top() == '('){
                stk.pop();
            }
            else{
                cout << "no" << '\n';
                flag = true;
                break;
            }
        }
        else if (a[i] == ']'){
            if (!stk.empty() && stk.top() == '['){
                stk.pop();
            }
            else{
                cout << "no" << '\n';
                flag = true;
                break;
            }
        }
    }
    if (flag == true) continue;
    if(stk.empty()) cout << "yes" << '\n';
    else cout << "no" << '\n';
    }
}