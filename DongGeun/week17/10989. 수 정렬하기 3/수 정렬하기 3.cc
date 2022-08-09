#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin>>m;
        arr[m]++;
    }
    for (int i=1;i<=10000;i++)
    {
        for(int j=0;j<arr[i];j++)
        {
            cout<<i<<'\n';
        }
    }

}


