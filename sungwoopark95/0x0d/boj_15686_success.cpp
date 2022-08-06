#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
using namespace std;

// 1. manhattan 거리 측정하는 함수
// 2. 개별 집과 치킨집의 주소를 저장한 다음,
// 3. 정해진 M개만큼 전체 조합을 만든다.
// 4. 개별 집에서 가장 가까이에 있는 치킨집까지의 거리들을 더한다.

int N, M;
int city[52][52];
int arr[20];
bool isused[20];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<vector<int>> combs;

int Manhattan(int x1, int x2, int y1, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

void MakeComb(int cur, int N, int M) {
    if (cur == M) {
        vector<int> idx;
        for (int i=0;i<M;i++) { idx.push_back(arr[i]); }
        combs.push_back(idx);
        return;
    }
    
    for (int i=0;i<N;i++) {
        if (!isused[i]) {
            if (cur >= 1 && arr[cur-1] > i) { continue; }
            arr[cur] = i;
            isused[i] = 1;
            MakeComb(cur+1, N, M);
            isused[i] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> city[i][j];
            if (city[i][j] == 2) { chicken.push_back({i, j}); }
            if (city[i][j] == 1) { house.push_back({i, j}); }
        }
    }
    
    MakeComb(0, (int)chicken.size(), M);
    
    int min_dist = INT_MAX;
    for (int i=0;i<(int)combs.size();i++) { // 각각의 조합들에 대해서 ex. 2개를 뽑는 경우라고 하면 (0, 1)에 대해서 -> // (0, 2)에 대해서 ...
        int dist_sum = 0;
        for (int j=0;j<(int)house.size();j++) { // 각각의 집마다
            int min_house_dist = INT_MAX;
            for (int k=0;k<(int)combs[i].size();k++) { // 각각의 조합으로 생기는 전체 치킨집들; 즉 0번째 치킨집과 1번째 치킨집에 대해서
                pair<int, int> store = chicken[combs[i][k]]; // combs[0] = (0, 1); combs[0][1] = 0; chicken[combs[0][1]] = 0번째 치킨집의 좌표
                int house_dist = Manhattan(house[j].first, store.first, house[j].second, store.second); // 집과 각 치킨집과의 거리 측정
                min_house_dist = min(min_house_dist, house_dist); // 그 가운데 거리가 최소인 치킨집을 살리고, 더 먼 치킨집을 폐업
            }
            dist_sum += min_house_dist; // 그렇게 개별 집집마다 최소의 거리가 나온 치킨집들의 조합에 대한 전체 거리를 측정
        }
        min_dist = min(min_dist, dist_sum); // 그 가운데에서도 최소의 거리를 기록한 치킨집 조합을 선택
    }
    
    cout << min_dist << "\n";
    
    return 0;
}