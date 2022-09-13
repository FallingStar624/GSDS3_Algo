#include <iostream>
#include <algorithm>
using namespace std;

int N, max_pay;
int day[20];
int pay[20];
int pay_sub[20];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> day[i];
        cin >> pay[i];
        pay_sub[i] = pay[i];
    }
    
    for (int i=1;i<=N;i++) {
        for (int j=1;j<i;j++) {
            if (j+day[j] <= i) { // 날짜 + 소요시간을 합친게 오늘 날짜보다 작거나 같다면
                // pay[i] -> i번째 날에 일함으로써 얻을 수 있는 최대 수익
                // pay_sub[i] -> i번째 날에 일함으로써 얻게 되는 일당
                pay[i] = max(pay[i], pay_sub[i] + pay[j]);
            }
        }
    }

    for (int i=1;i<=N;i++) {
        if (i+day[i] <= N+1 && max_pay < pay[i]) {
            // 전체 일하는 날이 N+1을 넘을 수 없음
            max_pay = pay[i];
        }
    }

    cout << max_pay << "\n";
    
    return 0;
}