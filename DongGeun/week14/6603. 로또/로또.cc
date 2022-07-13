#include <bits/stdc++.h>
using namespace std;
int arr[15];
int res[15];
int n,m;
bool isused[15];

void func(int k)
{
    if (k==6)
    {
        for (int i=0;i<6;i++)
        {
            cout<<res[arr[i]]<<' ';
        }
        cout<<'\n';
        return;
    }

    int st = 0;
    if(k != 0) st = arr[k-1];
    for(int i = st; i < n; i++){
        if(!isused[i])
        {
            arr[k] = i;
            isused[i]=1;
            func(k+1);
            isused[i]=0;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin>>n;
    while(n)
    {
        for (int i=0;i<n;i++) cin>>res[i];
        func(0);
        cout<<"\n";
        cin>>n;
    }
}
