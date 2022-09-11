#include <iostream>
#include <algorithm>
#define MAX 10005
using namespace std;

// boj_2579 계단 문제 응용

int n, maxval;
int wine[MAX];
int d[3][MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for (int i=1;i<=n;i++) { cin >> wine[i]; }

    d[1][1] = wine[1]; d[2][1] = 0; // 시작점 정의
    d[0][1] = max(d[1][1], d[2][1]);
    int temp_max = 0;
    for (int i=2;i<=n;i++) {
        if (temp_max < d[0][i-2]) { temp_max = d[0][i-2]; }
        d[1][i] = temp_max + wine[i];
        d[2][i] = d[1][i-1] + wine[i]; // 연달아 2번째 집은 와인은 얄짤 없이 그 바로 앞의 값에 더해야 함
        d[0][i] = max(d[1][i], d[2][i]);
    }
    
    cout << *max_element(d[0]+1, d[0]+n+1) << "\n";

    return 0;
}