#include <iostream>
#include <algorithm>
#define start first
#define end second
using namespace std;

int N;
pair<int, int> meeting[100002];

bool compare(const pair<int, int> &m1, const pair<int, int> &m2) {
    if (m1.end == m2.end) return m1.start < m2.start;
    return m1.end < m2.end;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> meeting[i].start >> meeting[i].end;
    }

    sort(meeting, meeting + N, compare);
    int cnt = 0;
    int end_time = 0;
    for (int i = 0; i < N; ++i) {
        if (meeting[i].start >= end_time) {
            cnt++;
            end_time = meeting[i].end;
        }
    }
    cout << cnt;

    return 0;
}