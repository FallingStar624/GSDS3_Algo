#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int occur[1001];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1;
    string str2;

    cin >> str1 >> str2;

    for(char c : str1) {
        occur[c - 'a']++;
    }

    for(char c : str2) {
        occur[c - 'a']--;
    }

    int answer = 0;
    for(int i = 0; i < 1001; i++) {
        
        if(occur[i] != 0) {
            answer += abs(occur[i]);
        }
        
    }

    cout << answer;

    return 0;
}