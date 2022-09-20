/*
문제 : 
두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것

Input : 
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 
문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자
https://www.acmicpc.net/problem/9251 

Output : 두 문자열의 LCS의 길이
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// int N;
// int input1[1002];
// int input2[1002];
int dp[1002][1002]; 
string a, b;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;

    int a_size = a.length();
    int b_size = b.length();
    
    for (int i=1; i<=a_size; i++){
        for (int j=1; j<=b_size; j++){
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[a_size][b_size] << '\n';

    return 0;
}