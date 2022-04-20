#include <bits/stdc++.h>
using namespace std;
int n,x;
int check[2000001];
int arr[100001];

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=0;i<n;i++)
    {    cin>>arr[i];}
    cin>>x;
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        if (x<=arr[i])
            continue;
        if(check[x-arr[i]])
            cnt++;
        else
        {
            check[arr[i]]=1;
        }
    }
    cout<<cnt;
}