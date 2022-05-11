#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        stack<char> s;
        string str;
        getline(cin, str);
        bool flag= true;
        if(str == ".") break;
        else
        {
            for (auto ch : str)
            {
                if(ch == '(' || ch == '[') s.push(ch);
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
                else if(ch == ']')
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
                else ;
            }
            if(!s.empty()) flag = false;
            if (flag) cout<<"yes\n";
            else cout<<"no\n";
        }
    }
}