// N개의 회의실 사용표, 겹치지 않도록 하는 회의의 최대 개수
// 한 회의 끝남과 동시에 다음 회의 시작
// 1st row: 회의의 수 1<=N<=100,000
// 2nd row ~ N+1th row: start time, end time ... 0<=, <=2^31-1

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
int st, en;

// 오름차순
bool cmp(pair<int, int> v1, pair<int, int> v2){
    if (v1.second==v2.second) return v1.first<v2.first;
    else return v1.second<v2.second;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for (int i=0; i<n; i++){
        cin>>st>>en;
        v.push_back(pair<int, int>(st, en)); // make_pair??
        // cin>>v[i].first>>v[i].second; -> main 내에서 v(n)으로 선언했을 때만
    }
    sort(v.begin(), v.end(), cmp);

    int cnt=1;
    int ord = v[0].second;
    for (int i=1; i<n; i++){
        if (v[i].first>=ord) {
            ord = v[i].second;
            cnt++;
        }
    }

    cout<<cnt;
    return 0;

}


// 모든 가능한 배정 방법 확인 -> O(2^N), 시간 초과
// 회의 끝나는 시간 빠른 순으로, 같으면 시작 시간 빠른 순으로 정렬 (최대한 많이 넣어야함) 
// DP-> O(N^2), 시간 초과
// greedy: 가능한 회의 (시작 시간이 현재 회의 끝나는 시간 이상) 중에서 가장 먼저 끝나는 회의를 택함

// pair & make_pair: https://oksk2003kr.tistory.com/5
// https://brightmango.tistory.com/264