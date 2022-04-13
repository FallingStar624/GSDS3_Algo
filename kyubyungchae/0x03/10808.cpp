#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int cntArr[26];

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;

    cin >> input;

    for(auto c : input) {
        cntArr[c - 'a']++;
    }

    for(int i = 0; i < 26; i++)
        cout << cntArr[i] << ' ';

    // for (char a = 'a'; a <= 'z'; a++) {
    //     int cnt = 0;
    //     for(auto c : input) {
    //         if (a == c) {
    //             cnt++;
    //         }
    //     }
    //     cout << cnt << ' ';
    // }

    return 0;
}