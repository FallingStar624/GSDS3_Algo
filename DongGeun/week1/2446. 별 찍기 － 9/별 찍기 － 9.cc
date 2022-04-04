#include <bits/stdc++.h>
using namespace std;
int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < i; k++) 
        {
            cout<<' ';
        }
        for(int a = 2*(n-i)-1; a >0; a--) {
            cout<<'*';
        }
        cout<<'\n';
    }

    for(int i = 1; i < n; i++) {
        for(int k = n-i-1; k >0; k--) 
        {
            cout<<' ';
        }
        for(int k = 0; k < 2*i+1; k++) 
        {
            cout<<'*';
        }
        cout<<'\n';
    }
}