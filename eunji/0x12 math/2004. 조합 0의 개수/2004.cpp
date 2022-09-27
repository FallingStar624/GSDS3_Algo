/*
nCk = n-1Ck + n-1Ck-1
*/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long n, m;
long long answer = 0;

int countfive(long long n){
    int ans = 0;
    while (n >= 5){
        ans += n/5;
        n /= 5;
    }
    return ans;
}

int counttwo(long long n){
    int ans = 0;
    while (n >= 2){
        ans += n/2;
        n /= 2;
    }
    return ans;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // cout << n;
    // cout << counttwo(25);

    int answer = min(counttwo(n)-counttwo(n-m)-counttwo(m), countfive(n)-countfive(n-m)-countfive(m));

    cout << answer;
    return 0;
}

