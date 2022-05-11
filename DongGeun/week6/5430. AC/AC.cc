#include <bits/stdc++.h>
using namespace std;
int N,K;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> N;
    string s,sequence;
    while(N-->0)
    {
        cin >> s>>K>>sequence;
        deque<int> Q;
        deque<int>::iterator iter;
        sequence = sequence.substr(1,sequence.length() - 2);
        istringstream iss(sequence);
        string buffer;
        while (getline(iss, buffer, ',')) {
            Q.push_back(stoi(buffer));
        }
        bool flag=true;
        bool check=false;
        for(auto i :s)
        {
            if (i=='R')
            {
                flag = (flag ==true) ? false : true;
            }
            else
            {
                if (flag)
                {
                    if (Q.empty())
                    {
                        check = true;
                        break;
                    }
                    Q.pop_front();
                }
                else
                {
                    if (Q.empty())
                    {
                        check = true;
                        break;
                    }
                    Q.pop_back();
                }

            }
        }
        if (check)
        {
            cout<<"error\n";
        }
        else
        {
            cout<<"[";
            while(!Q.empty())
            {
                if (flag)
                {
                    cout<<Q.front();
                    Q.pop_front();
                    if (!Q.empty())  cout<<",";
                }
                else
                {
                    cout<<Q.back();
                    Q.pop_back();
                    if (!Q.empty())  cout<<",";
                }
            }
            cout<<"]\n";
        }
    }

}