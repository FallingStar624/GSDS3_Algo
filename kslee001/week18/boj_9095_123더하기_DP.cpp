// https://www.acmicpc.net/problem/9095
#include <iostream>
using namespace std;
int d[11];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    d[0] = 0;  // 1 : 0
    d[1] = 1;  // 2: 1+1
    d[2] = 2;  // 3: 1+2, 2+1
    d[3] = 4;  // 4: 1+1+1+1, 1+1+2, 1+2+1, 2+1+1
    // 4를 n이라고 두면, 4를 만들 수 있는 가능한 경로 :
    // n-1까지의 조합 + 1  : 3만드는 조합 +1 -> 1+1+1, 1+2, 2+1  (+1)
    // n-2까지의 조합 + 2  : 2만드는 조합 +1 -> 1+1   (+1)
    // n-3까지의 조합 + 3  : 1만드는 조합 +1 -> 0 (+1)
    
    // d[4] = d[4-1] + d[4-2] + d[4-3]; 
    for(int i=4; i<11; ++i)
        d[i] = d[i-1] + d[i-2] + d[i-3];
    int n;
    cin >>n;
    for(int i=0; i<n; ++i){
        int input;
        cin >>input;
        cout << d[input] <<"\n";
    }
}