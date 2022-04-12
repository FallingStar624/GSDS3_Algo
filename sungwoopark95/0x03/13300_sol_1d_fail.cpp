#include <bits/stdc++.h>
using namespace std;

int students[12]; // 학년/성별로 몇명인지 세는 배열
// 0 - 1학년 여학생, 1 - 1학년 남학생, ..., 9 - 5학년 남학생, 10 - 6학년 여학생, 11 - 6학년 남학생
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 전체 인원과 방별 인원
    int N, k;
    cin >> N >> k;

    int sex, grade, idx; // 성별과 학년, 배열 index
    for (int i=0;i<N;i++) {
        cin >> sex >> grade;
        idx = (2 * grade) - 1 - (1 - sex);
        students[idx] += 1;
    }

    // 규칙에 따라서 students 돌면서 방 세기
    int room = 0;
    for (int j=0;j<12;j++) {
        // 오류난 부분; 나머지만큼 더하면 안 됨!
        room += (students[j] / k) + (students[j] % k);
    }

    cout << room << "\n";

    return 0;
}