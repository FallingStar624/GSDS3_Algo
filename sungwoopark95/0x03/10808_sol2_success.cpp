#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string word;
    cin >> word;
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int count[26];
    
    // initialize the count array
    for (int i=0;i<26;i++) {
        count[i] = 0;
    }

    // count each character;
    for (int j=0;j<word.length();j++) {
        for (int k=0;k<26;k++) {
            if (word[j] == alphabet[k]) {
                count[k] += 1;
            }
        }
    }

    // print out the count
    for (int l=0;l<26;l++) {
        cout << count[l] << " ";
    }
    cout << "\n";

    return 0;
}