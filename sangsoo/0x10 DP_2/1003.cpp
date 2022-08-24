#include <iostream>
using namespace std;

/*
algorithm
both dp_0 and dp_1 are fibonacci functions
?? 함수를 호출하면서 메모이제이션하는 방식으로 하면 왜 시간초과가 날까?
*/

int dp_0[42], dp_1[42];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp_0[0] = 1;
    dp_0[1] = 0;
    dp_0[2] = 1;
    dp_0[3] = 1;
    dp_1[0] = 0;
    dp_1[1] = 1;
    dp_1[2] = 1;
    dp_1[3] = 2;
    for(int i = 4; i < 41; i++){
        dp_0[i] = dp_0[i-1] + dp_0[i-2];
        dp_1[i] = dp_1[i-1] + dp_1[i-2];
    }
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int a;
        cin >> a;
        cout << dp_0[a] << " " << dp_1[a] << '\n';}

}