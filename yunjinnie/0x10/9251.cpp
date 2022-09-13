// Longest Common Subsequence
// 1st, 2nd row: 2 strings, all capital, len(1000)

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a, b;
int d[1002][1002] = {0, }; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;

    for (int i=0; i<a.length(); i++){
        for (int j=0; j<b.length(); j++){
            // 0, C, CA, CAP ... vs  ACAYKP
            if (a[i]==b[j]) d[i+1][j+1] = d[i][j]+1;
            else d[i+1][j+1] = max(d[i+1][j], d[i][j+1]);
        }
    }

    cout<<d[a.length()][b.length()];
    return 0;
}

// 연속 x, 최대 공통 부분 문자 찾기
// 두 문자열 하나씩 비교하면 시간초과
// for문 2개 ... a[i]=b[j] -> d[i+1][j+1] = d[i][j]+1
// https://ongveloper.tistory.com/36
