#include <bits/stdc++.h>
using namespace std;

void char_count(string str, int *arr);

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num;
    string a, b;
    
    cin >> num;

    for (int i=0;i<num;i++) {
        cin >> a >> b;

        int countA[26], countB[26];
        for (int i=0;i<26;i++) {
            countA[i] = 0;
            countB[i] = 0;
        }

        char_count(a, countA);
        char_count(b, countB);

        int diff = 0;
        for (int i=0;i<26;i++) {
            if (countA[i] != countB[i]) {
                diff += 1;
            }
        }

        if (diff == 0) {
            cout << "Possible" << "\n";
        } else{
            cout << "Impossible" << "\n";
        }

    }

    return 0;
}

void char_count(string str, int *arr) {
    // a -> z의 순서대로 등장 횟수를 세는 배열
    for (int i=0;i<(int)str.length();i++) {
        char c = str[i];
        arr[c-'a'] += 1;
    }
}