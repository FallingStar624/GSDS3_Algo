#include <bits/stdc++.h>
using namespace std;
int cnt,sum;
bool check(string st);
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    stack<int> s;
    string str;
    getline(cin, str);
    bool flag=  check(str);
    if (flag)
    {
        for (auto ch : str)
        {
            if(ch == '(' || ch == '[') s.push(ch);
            else if (ch==')')
            {
                if (s.top()=='(')
                {
                    s.pop();
                    s.push(2);
                }
                else
                {
                    int temp=0;
                    while(s.top()!='(')
                    {
                        temp+=s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push(temp*2);
                }
            }
            else if (ch==']')
            {
                if (s.top()=='[')
                {
                    s.pop();
                    s.push(3);
                }
                else
                {
                    int temp=0;
                    while(s.top()!='[')
                    {
                        temp+=s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push(temp*3);
                }
            }
        }
        while(!s.empty())
        {
            //cout<<s.top()<<"\n";
            cnt+=s.top();
            s.pop();
        }
        cout<<cnt;
    }
    else cout<<"0";
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