#include <bits/stdc++.h>
using namespace std;
int cnt;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    stack<char> s;
    string str;
    getline(cin, str);
    char prev=' ';
    for (auto ch : str)
    {
        if (ch=='(')s.push(ch);
        else
        {
            if (prev=='(')
            {

                s.pop();
                cnt+=s.size();
            }
            else
            {
                s.pop();
                cnt++;
            }
        }
        prev=ch;
    }
    cout<<cnt;
}