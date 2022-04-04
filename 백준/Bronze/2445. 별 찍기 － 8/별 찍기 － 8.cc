#include <bits/stdc++.h>
using namespace std;
int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int k = 0; k <= i; k++) 
        {
            cout<<'*';
        }
        for(int a = (n-i-1)*2; a >0; a--) {
            cout<<' ';
        }
        for(int k = 0; k <= i; k++) 
        {
            cout<<'*';
        }
        cout<<'\n';
    }
    for(int i = 1; i < n; i++) {
        for(int k = n; k > i; k--) 
        {
            cout<<'*';
        }
        for(int a = 0; a <2*i; a++) {cout<<' '; }
        for(int k = n; k > i; k--) 
        {
            cout<<'*';
        }
        cout<<'\n';
    }
}