/*
문제 : 
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램

Input : T (test case #)
Output : n (0<n<11) 
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int T;
int answer[12];    
int input[12];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> input[i]; 
    }

    answer[1] = 1;
    answer[2] = 2;
    answer[3] = 4;
    for (int i=4; i<12; i++){
        answer[i] = answer[i-1]+answer[i-2]+answer[i-3];
    }

    for (int i=0; i<T; i++){
        cout << answer[input[i]] << '\n';   
    }
    return 0;
}