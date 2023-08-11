#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isMatch(const string& p, const string& fname) {
    int pLen = p.length();
    int fLen = fname.length();

    // dp[i][j] : 패턴 i글자와  파일 이름의 앞 j글자가 일치
    vector<vector<bool>> dp(pLen + 1, vector<bool>(fLen + 1, false));

    dp[0][0] = true;

    for(int i = 1; i <= pLen && p[i-1] == '*'; ++i) {
        dp[i][0] = true;
    }

    for(int i = 1; i <= pLen; ++i) {
        for(int j = 1; j <= fLen; ++j) {
            if(p[i-1] == '*' || p[i-1] == fname[j-1])
                dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1];
        }
    }
    return dp[pLen][fLen];
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string p;
    cin >> p;

    for(int i = 0; i < N; ++i) {
        string fname;
        cin >> fname;

        if (isMatch(p, fname)) {
            cout << "DA" << '\n';
        } else {
            cout << "NE" << '\n';
        }
    }


    return 0;
}