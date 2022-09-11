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
using namespace std;

int N;
int input1[1002];
int input2[1002];
int dp[1002]; 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> input1[i];
        // 수정 중
    }



    return 0;
}