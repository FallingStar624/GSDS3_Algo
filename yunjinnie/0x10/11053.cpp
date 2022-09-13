// longest increasing subset
// 1st row: len(A), 1<=N<=1000
// 2nd row: components, 1<=Ai<=1000

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[1002];
int num[1002];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for (int i=1; i<=n; i++){
        cin>>num[i];
        //d[i] = num[i];
    }
    int s = 0;

    for (int i=1; i<=n; i++){
        d[i] = 1; // default len
        for (int j=1; j<=i; j++){
            if (num[j]<num[i]){ // increasing
                d[i] = max(d[i], d[j]+1); // new case : d[j]+한 칸
            }
        }
        s = max(d[i], s);
    }

    cout << s;
    return 0;

}

// d[i] : ith value가 가지는 LIS
// https://lesslate.github.io/onlinejudge/Baekjoon-11053%EB%B2%88/