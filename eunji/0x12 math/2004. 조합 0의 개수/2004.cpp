/*
nCk = n-1Ck + n-1Ck-1
*/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long n, m;
long long answer = 0;

int counttwo(long long n){
    int ans = 0;
    for (long long i=1; i<=n; i++){
        int count = 0;
        while (1){
            if (i % 2 == 0) count ++;
            else break;
        }
        ans += count;
    }   
    return ans;
}

int countfive(long long n){
    int ans = 0;
    for (long long i=1; i<=n; i++){
        int count = 0;
        while (1){
            if (i % 5 == 0) count ++;
            else break;
        }
        ans += count;
    }   
    return ans;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // cout << n;
    cout << counttwo(25);

    // int answer = min(counttwo(n)-counttwo(n-m)-counttwo(m), countfive(n)-countfive(n-m)-countfive(m));

    // cout << answer;
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