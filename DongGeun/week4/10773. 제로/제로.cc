#include <bits/stdc++.h>
using namespace std;
int N,K;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    stack<int> S;
    long int sum=0;
    while(N-->0)
    {
        cin>>K;
        if (K>0)
        {
            S.push(K);
            sum+=K;
        }
        else
        {
            sum-=S.top();
            S.pop();
        }
    }
    cout<<sum;
}