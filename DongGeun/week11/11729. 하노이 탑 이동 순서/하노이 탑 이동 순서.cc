#include <bits/stdc++.h>
using namespace std;
void func(int a,int b, int c)
{
    if (c==1)
    {
        cout<<a<<' '<<b<<'\n';
        return;
    }
    func(a,6-a-b,c-1    );
    cout<<a<<' '<<b<<'\n';
    func(6-a-b,b,c-1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int a;
    cin>>a;
    cout<<(1<<a)-1<<'\n'; //pow 는 안됨
    func(1,3,a);
}