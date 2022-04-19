#include <bits/stdc++.h>
using namespace std;

int N;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N-->0)
    {
        string S;
        cin>>S;
        list<char> L={};
        list<char>::iterator t=L.begin();
        //auto t=L.begin();

        for (auto c : S)
        {
            if (c=='<')
            {
                if (t != L.begin()) t--;
            }
            else  if (c=='>')
            {
                if (t != L.end()) t++;
            }
            else if (c=='-')
            {
                if (t!=L.begin())
                {
                    t--;
                    //cout <<*t<<" deleted \n";
                    t=L.erase(t);
                }

            }
            else {
                L.insert(t, c);
                //for (auto s : L)cout<<s;
                //cout<<'\n';
            }


        }
        for (auto c : L)cout<<c;
        cout<<'\n';

    }


}