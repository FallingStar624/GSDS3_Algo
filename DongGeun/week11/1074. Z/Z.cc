#include <bits/stdc++.h>
using namespace std;
int func(int a,int b, int c)
{
    if (a==1)
    {
        return 2*b+c;
    }
    int x=1<<(a-1);
    if (b<x &&c<x) return func(a-1,b,c);
    if (b<x &&c>=x) return x*x+func(a-1,b,c-x);
    if (b>=x &&c<x) return 2*x*x+func(a-1,b-x,c);
    return 3*x*x+func(a-1,b-x,c-x);

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<func(a,b,c);
}