/*
문제 : 
N개의 회의에 대하여 회의실 사용표 만들기
각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 
각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수는?

Input : 
회의의 수 N(1 ≤ N ≤ 100,000)
N+1 줄까지 각 회의의 시작시간과 끝나는 시간
시작 시간과 끝나는 시간은 2^31-1보다 작거나 같은 자연수 또는 0

Output : 
최대 사용할 수 있는 회의의 최대 개수
*/

#include <algorithm>
#include <iostream>
using namespace std;

int N; 
int answer;

typedef struct {
    int s; // start
    int e; // end
    int d; // duration
} meeting;

// vector<meeting> m;
meeting m[100002];

bool compare(const meeting &a, const meeting &b){
    if (a.e < b.e) return true;
    else if (a.e == b.e){
        if (a.s < b.s) return true;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> m[i].s >> m[i].e;
        m[i].d = m[i].e - m[i].s;
    }

    sort(m, m+N, compare);

    // for (int i=0; i<N; i++){
    //     cout << m[i].s << ' ' << m[i].e << '\n';
    // }

    int end = 0;
    for (int i=0; i<N; i++){
        if (end <= m[i].s) {
            end = m[i].e;
            answer += 1;
        }
        else continue;
    }

    cout << answer;

    return 0;
}