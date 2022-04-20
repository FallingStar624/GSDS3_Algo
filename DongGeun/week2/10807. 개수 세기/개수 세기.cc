#include <bits/stdc++.h>
using namespace std;
int n,x,cnt;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    int arr[100];
    for (int i=0;i<n;i++)
    {    cin>>arr[i];}
    cin>>x;
    for (int i=0;i<n;i++)
    {    
        if (arr[i]==x)
        {
        cnt++;
        }
    }
    cout<<cnt;
}