#include <bits/stdc++.h>
using namespace std;

int countA[26];
int countB[26];

void char_count(string &str, bool is_A=true);
int abs(int x);

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 두 string에 등장한 character의 횟수 담아놓는 배열 형성한 뒤, 각각의 위치별로 비교해서 같으면 pass, 다르면 그 차이만큼 더해줌
    // 횟수를 담아놓는 배열은 a -> z의 순서로 이루어졌다고 가정
    string a, b;
    cin >> a >> b;

    char_count(a);
    char_count(b, false);

    int cnt = 0;
    int diff;
    for (int i=0;i<26;i++) {
        if (countA[i] != countB[i]) {
            diff = countA[i] - countB[i];
            cnt += abs(diff);
        }
    }
    
    cout << cnt << "\n";

    return 0;
}

void char_count(string &str, bool is_A) {
    char c;
    for (int i=0;i<(int)str.length();i++) {
        c = str[i];
        if (is_A) {
            countA[c-'a'] += 1;
        } else {
            countB[c-'a'] += 1;
        }
    }
}

int abs(int x) {
    if (x >= 0) {return x;}
    else {return (-1) * x;}
}