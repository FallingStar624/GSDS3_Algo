#include <bits/stdc++.h>
using namespace std;

int N;
long long cnt;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    long long K;
    stack<long long> S;
    for (int i=0;i<N;i++)
    {
        cin >> K;
        if (!S.empty()&&S.top()>K)
        {
            //cout<<S.size()<<" Stack size \n";
            cnt += S.size();
            //cout<<K<<"is added \n\n";
        }
        else
        {
            while (!S.empty())
            {
                if (S.top()>K)
                {
                    //cout<<S.size()<<" Stack size \n";
                    cnt += S.size();
                    break;
                }
                //cout<<S.top()<<"is deleted \n\n";
                S.pop();
            }
            //cout<<K<<"is added \n\n";
        }
        S.push(K);
    }
    cout<<cnt;
}
