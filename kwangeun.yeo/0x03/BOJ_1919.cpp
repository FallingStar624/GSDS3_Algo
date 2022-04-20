#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int w1[30];
int w2[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> s1 >> s2;
    for (char c: s1) w1[c - 'a']++;
    for (char c: s2) w2[c - 'a']++;

    int delWord = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        delWord += abs(w1[i - 'a'] - w2[i - 'a']);
    }
    cout << delWord;

    return 0;
}