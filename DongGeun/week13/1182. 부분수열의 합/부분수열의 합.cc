#include <bits/stdc++.h>
using namespace std;
int n,k,cnt;

int arr[40];

void func(int cur,int tot)
{
    if (cur==n)
    {
        if(tot==k)
        {
            cnt++;
        }
        return;
    }
    func(cur+1,tot);
    func(cur+1,tot+arr[cur]);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n>>k;
    for (int i=0;i<n;i++)cin>>arr[i];
    func(0,0);
    if (k==0)cnt--;
    cout<<cnt;



}
