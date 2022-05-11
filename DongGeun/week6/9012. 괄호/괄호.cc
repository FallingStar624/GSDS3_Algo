#include <bits/stdc++.h>
using namespace std;
int N,cnt;
bool check(string st);
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("input.txt","r",stdin);
    cin>>N;
    while(N-->0)
    {
        string str;
        cin>>str;
        if (check(str))
        {
            cout<<"YES\n";
        }
        else cout<<"NO\n";

    }
}
bool check(string st)
{
    stack <char> s;
    bool flag= true;
    for (auto ch : st)
    {
        if(s.empty()) {
            s.push(ch);
            continue;
        }
        if(ch == '('||ch == '[') {
            s.push(ch);
        }
        else if(ch == ')')
        {
            flag= false;
            if (s.empty())break;
            else if (s.top()=='(')
            {
                flag=true;
                s.pop();
            }
            else break;
        }
        else
        {
            flag= false;
            if (s.empty())break;
            else if (s.top()=='[')
            {
                flag=true;
                s.pop();
            }
            else break;
        }
    }
    if(!s.empty()) flag = false;
    return flag;
}