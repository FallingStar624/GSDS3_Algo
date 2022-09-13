#include <iostream>
#include <string>
using namespace std;

// 답안 보고 이해한 내용임.

string str1, str2;
int N, M;
int answer[2010][2010];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> str1 >> str2;
    N = str1.length();
    M = str2.length();
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            if (str1[i-1] == str2[j-1]) { answer[i][j] = answer[i-1][j-1] + 1; }
            else { answer[i][j] = max(answer[i-1][j], answer[i][j-1]); }
        }
    }
    
    cout << answer[N][M] << "\n";
    return 0;
}