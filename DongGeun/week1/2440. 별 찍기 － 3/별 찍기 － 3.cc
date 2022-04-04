#include <bits/stdc++.h>
using namespace std;

    
int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = n; i >0; i--) 
    {
        for (int j=0;j<i;j++)
        {
            cout<<'*';
        }
        cout<<'\n';
    }
}