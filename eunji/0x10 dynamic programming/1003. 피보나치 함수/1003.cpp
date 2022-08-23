/*
문제 : 
N이 주어졌을 때, fibonacci(N)을 호출했을 때, 
0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오

Input : T (test case #)
Output : N (0<=N<=40) 
*/

#include <algorithm>
#include <iostream>
using namespace std;

int T; 
int d[42][2]; // dim_2 : fib(0), fib(1)

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    d[0][0] = 1;
    d[0][1] = 0;
    d[1][0] = 0;
    d[1][1] = 1;
    d[2][0] = 1;
    d[2][1] = 1;
    for (int i=3; i<42; i++){
      d[i][0] = d[i-1][0]+d[i-2][0];
      d[i][1] = d[i-1][1]+d[i-2][1];

    }

    for (int i=0; i<T; i++){
      int q;
      cin >> q;
      cout << d[q][0] << ' ' << d[q][1] << '\n';   
    }

    return 0;
}