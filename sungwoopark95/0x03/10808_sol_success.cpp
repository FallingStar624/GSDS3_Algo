#include <bits/stdc++.h>
using namespace std;

int freq[26];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string word;
    cin >> word;

    // count each character;
    for (int j=0;j<word.length();j++) {
        char c = word[j];
        freq[c - 'a'] += 1;
    }

    // print out the count
    for (int l=0;l<26;l++) {
        cout << freq[l] << " ";
    }
    cout << "\n";

    return 0;
}