#include <bits/stdc++.h>
using namespace std;

int students[6][2]; // 6 x 2 matrix
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 전체 인원과 방별 인원
    int N, k;
    cin >> N >> k;

    int sex, grade;
    for(int i=0;i<N;i++) {
        cin >> sex >> grade;
        students[grade-1][sex]++;
    }

    int room = 0;
    for (int i=0;i<6;i++) {
        for (int j=0;j<2;j++) {
            int members = students[i][j];
            room += (members / k);
            if (members % k > 0) {// 인원이 남으면 1개만 더해주면 됨
                room++;
            }
        }
    }

    cout << room << "\n";

    return 0;
}