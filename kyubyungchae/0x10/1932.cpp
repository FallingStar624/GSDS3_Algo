#include <iostream>
#include <algorithm>

using namespace std;

int triangle[502][502];
int d[502][502];

/*
1. 테이블 정하기
d[floor][i] = 삼각형 floor에서 i칸까지 오는데 걸린 비용

2. 점화식 찾기 
d[floor][i] = max(d[floor - 1][i-1], d[floor - 1][i]) + triangle[floor][i]

3. 초기값 정하기
d[1][1] = triangle[1][1]
*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            cin >> triangle[i][j];
    d[1][1] = triangle[1][1];

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + triangle[i][j];
        }
    }

    cout << *max_element(d[n] + 1, d[n] + n + 1);

    return 0;
}