#include <iostream>
using namespace std;
int n;
int score[301];
int now1[301];
int now2[301];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> score[i];
    }
    now1[1]=score[1];
    now1[2]=score[2];
    now2[2]=score[1]+score[2];

    for (int i=3; i<=n; i++) {
        int cur_score = score[i];
        now1[i] = max(now1[i-2]+cur_score, now2[i-2]+cur_score);
        now2[i] = now1[i-1]+cur_score;
    }
    cout << max(now1[n], now2[n]);
    return 0;
}
