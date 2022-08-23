// fibonacci 
// 1st row: # of test case T
// 2nd row~: test case N (0<=N<=40)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, int>> fib;
int t, n;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fib.push_back(make_pair(1, 0));
    fib.push_back(make_pair(0, 1));
    cin >> t;
    //for (int i=0; i<t; i++){
    while(t--){
        cin>> n;
        for(int i=2; i<=40; i++){ // n -> 나머지에 trash val
            fib.push_back(make_pair((fib[i-2].first + fib[i-1].first), (fib[i-2].second+fib[i-1].second)));
        }
        cout << fib[n].first << " "<< fib[n].second << '\n';

    }

}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// d[0] = 1, 0
// d[1] = 0, 1
// d[2] = 1, 1
// d[3] = 1, 2 = fib(2) + fib(1)
// d[4] = fib(3) + fib(2)
// https://wonsang98.tistory.com/58