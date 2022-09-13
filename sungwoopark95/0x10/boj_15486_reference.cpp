#include <iostream>
#include <algorithm>
#define MAX 1500100
using namespace std;

// 답안을 보고 해석한 내용임 - RL과 연결되는 문제

int N, max_pay;
int day[MAX];
int pay[MAX];
int pay_sub[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> day[i];
        cin >> pay[i];
    }
    
    for (int i=N;i>=1;i--) { 
        if (i+day[i] <= N+1) {
            /*
            상담을 할 수 있다면, 상담을 했을 때 vs 하지 않았을 때를 비교
            상담하지 않는다면, 결국 아래처럼 그날 얻게 되는 value는 다음날 얻게 되는 value와 동일함.
            상담한다면, 그날 얻게 되는 value는 그날 얻는 reward + after 상담으로 얻게 될 value들의 합과 동일함.
            */
            pay_sub[i] = max(pay_sub[i+1], pay_sub[i+day[i]] + pay[i]);
        } else {
            /*
            상담을 할 수 없다면, i번째 일에 얻게 되는 일당은 0이므로,
            결국 그날 얻게 되는 value는 다음날 얻게 되는 value와 동일함
            */ 
            pay_sub[i] = pay_sub[i+1];
        }
    }

    for (int i=1;i<=N+1;i++) {
        if (max_pay < pay_sub[i]) {
            // 전체 일하는 날이 N+1을 넘을 수 없음
            max_pay = pay_sub[i];
        }
    }

    cout << max_pay << "\n";
    
    return 0;
}