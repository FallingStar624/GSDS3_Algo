#include <iostream>
#include <algorithm>
#define MAX 10005
using namespace std;

// boj_2579 계단 문제 응용

int n, maxval;
int wine[MAX];
int maximums[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for (int i=1;i<=n;i++) { cin >> wine[i]; }

    for (int i=1;i<=n;i++) { // 첫 시작을 몇 번째 잔으로 할 것인가
        int d[MAX][3]; // 각 시작점(i)마다 boj_2579 계단 문제에 사용했던 3열짜리 배열 생성
        d[i][1] = wine[i]; d[i][2] = 0; // 시작점 정의
        d[i][0] = max(d[i][1], d[i][2]);
        int temp_max = d[i][0]; int temp = 0;
        for (int j=i+1;j<=n;j++) {
            /*
            point: 이전에 마신 와인에서 현재 도달한 와인까지 몇 칸을 건너뛰든 상관 없음
            -> 계단 문제와의 차이점; 계단 문제는 반드시 2칸 또는 1칸을 뛰어넘어야 함
            -> 따라서, j번째 와인을 처음 연달아 집은 경우, 
                최소 j-2번째 이전까지 마신 와인의 최댓값에 j번째 와인의 양을 더해주어야 함
            */ 
            if (temp < d[j-2][0]) { temp = d[j-2][0]; } 
            d[j][1] = temp + wine[j];
            d[j][2] = d[j-1][1] + wine[j]; // 연달아 2번째 집은 와인은 얄짤 없이 그 바로 앞의 값에 더해야 함
            d[j][0] = max(d[j][1], d[j][2]);
            if (temp_max < d[j][0]) { temp_max = d[j][0]; }
        }
        maximums[i] = temp_max;
        if (maxval < maximums[i]) { maxval = maximums[i]; }
    }

    cout << maxval << "\n";
    
    return 0;
}