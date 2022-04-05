#include <bits/stdc++.h>
using namespace std;
int cnt[26];
    
int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for (auto chr : s)
    {
        cnt[chr-'a']++;
    }
    for (int i=0;i<26;i++)
    {
        cout<<cnt[i]<<' ';
    }
}