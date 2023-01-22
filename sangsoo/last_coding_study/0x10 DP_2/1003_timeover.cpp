#include <iostream>
using namespace std;

/*
algorithm
both dp_0 and dp_1 are fibonacci functions
?? 함수를 호출하면서 메모이제이션하는 방식으로 하면 왜 시간초과가 날까?
*/

int dp_0[42], dp_1[42];

int fb_0(int n){
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 1;
    dp_0[0] = 1;
    dp_0[1] = 0;
    dp_0[2] = 1;
    dp_0[3] = 1;
    dp_0[n] = fb_0(n-1) + fb_0(n-2);   
    return dp_0[n];
}

int fb_1(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 2;
    dp_1[0] = 0;
    dp_1[1] = 1;
    dp_1[2] = 1;
    dp_1[3] = 2;
    dp_1[n] = fb_1(n-1) + fb_1(n-2);   
    return dp_1[n];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int a;
        cin >> a;
        cout << fb_0(a) << " " << fb_1(a) << '\n';}

}