#include <bits/stdc++.h>
using namespace std;
long long func(long long a,long long b,long long c);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    long long A, B, C;
    cin>>A>>B>>C;
    cout<<func(A,B,C);
}
long long func(long long a,long long b,long long c)
{
    if (b==1) return a%c;
    if (b%2==0)
    {
        auto tmp =func(a,b/2,c);
        return (tmp*tmp)%c;
    }
    else return (func(a,b-1,c)*a)%c;
}
