#include <bits/stdc++.h>
using namespace std;
int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = n; j > 0; j--)
        {
            if (j>i+1)
            {
                cout<<' ';
            }
            else
            {
                cout<<'*';
            }
        }
        for(int k = 0; k < i; k++)
        {
            cout<<'*';
        }
        cout<<'\n';
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++)
        {
            if (j>=i)
            {
                cout<<'*';
            }
            else
            {
                cout<<' ';
            }
        }
        for(int k = n-i-1; k > 0; k--)
        {
            cout<<'*';
        }
        cout<<'\n';
    }
}