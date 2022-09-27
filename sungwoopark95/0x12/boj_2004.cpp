#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;

int number_cnt(int n, int criterion){
    int cnt = 0;
    while (n != 0){
        n = n / criterion;
        cnt += n; // n까지의 k의 개수 == n까지의 모든 수를 k로 나눈 몫의 전체 합
    }
    return cnt;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    int twos = number_cnt(n, 2) - number_cnt(m, 2) - number_cnt(n-m, 2);
    int fives = number_cnt(n, 5) - number_cnt(m, 5) - number_cnt(n-m, 5);

    cout << min(twos, fives) << "\n";
    return 0;
}
