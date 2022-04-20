#include <bits/stdc++.h>
using namespace std;

int N;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    string S;
    cin>>S;
    cin >> N;
    list<char> L={};
    for (auto c : S)L.push_back(c);
    list<char>::iterator t=L.end();
    while (N-->0)
    {
        char op;
        cin>>op;
        switch (op)
        {
            case 'P':
                char plus;
                cin >> plus;
                L.insert(t, plus);
                //t++;
                break;
            case 'L':
                if (t != L.begin()) t--;
                break;

            case 'D':
                if (t != L.end()) t++;
                break;

            case 'B':
                if (t != L.begin())
                {
                    t--;
                    t=L.erase(t);
                }
                break;

        }
        //for (auto c : L)cout<<c;
        //cout<<"\n";
    }
    for (auto c : L)cout<<c;


}