// https://www.acmicpc.net/problem/9461 파도반수열 DP
#include <iostream>
using namespace std;

/*
1. define base case
white[1] = 1
white[2] = 2
blue[1] = 1
blue[2] = 1
blue[3] = 2

2. find relation
white[3] = blue[1]  + blue[3]  = 1 + 2 = 3
blue[4]  = white[1] + white[3] = 1 + 3 = 4

white[4] = blue[2] + blue[4]   = 1 + 4 = 5
blue[5]  = white[2] + white[4] = 2 + 5 = 7
...

3. define relation
arr[]
white[i+2] = blue[i] + blue[i+2]   (i>=1)
blue [i+3] = white[i] + white[i+2] (i>=2) 

짝수 index는 blue (! idx%2)
    -> print blue[idx/2]
홀수 index는 white (idx%2)
    -> print white[idx/2]

*/

unsigned long long dp[110];
unsigned long long blue[110];
unsigned long long white[110];
unsigned long long t,n;
unsigned long long res;

int main(){
    // base case
    white[1] = 1;
    white[2] = 2;
    blue[1] = 1;
    blue[2] = 1;
    blue[3] = 2;

    // dp (blue 는 4부터, white는 3부터 정의 가능하도록 i=1 설정)
    for(int i=1; i<=100; ++i){
        // white[3] = blue[1] + blue[3]
        // blue[4]  = white[]
        white[i+2] = blue[i] + blue[i+2];
        blue [i+3] = white[i] + white[i+2]; 
    }

    for(int i=1; i<=50; ++i){
        dp[2*i-1] = blue[i];
        dp[2*i  ] = white[i];
    }

    cin >>t;
    for(int i=0; i<t; ++i){
        cin >>n;
        printf("%lld\n", dp[n]);
    }

}