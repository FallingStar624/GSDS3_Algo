#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; int out = 0;
    cin >> N ;
    cin.ignore(); // 중요! cin.ignore()를 하지 않으면 버퍼에 '\n'이 남아있음
    while (N--){
        string s;
        getline(cin, s);
        stack<char> stk;
        for (int i = 0; i < s.length() ; i++){
            if (stk.empty()) stk.push(s[i]);
            else if (s[i] == 'A'){
                if (stk.top() == 'A') stk.pop();
                else stk.push(s[i]);
            }
            else if (s[i] == 'B'){
                if (stk.top() == 'B') stk.pop();
                else stk.push(s[i]);
            }
        }
        if (stk.empty()) out++;
    }
    cout << out;
}