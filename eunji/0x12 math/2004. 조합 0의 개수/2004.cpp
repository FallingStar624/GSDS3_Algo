/*
nCk = n-1Ck + n-1Ck-1
*/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long n, m;
// long long dp[2000000002][2000000002];
long long product;
long long answer = 0;



int count2(long long a){
    for (int i=1; i<=n; i++){
        if (i % 5)
    }   

}

int count5(long long a){
    for (int i=1; i<=n; i++){
        if (i % 5)
    }   

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    int A = count2(n-m+1); // n-r+1까지
    int B = count5(n-m+1);
    int C = count2(m); // n-r
    int D = count5();

    // cout2(n)
    int answer;
    answer = A + B - C - D;

    cout << count1+
    return 0;
}




// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m;

//     product = LCM(n, m);
//     while (product % 10 == 0){
//         product = product / 10;
//         answer ++;
//     }

//     cout << answer;

//     return 0;
// }