#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
using namespace std;

// 1. manhattan 거리 측정하는 함수
// 2. 개별 집과 치킨집의 주소를 저장한 다음,
// 3. 개별 치킨집이 선택되는 횟수 count -> 그 횟수가 0이거나 가장 작은 치킨집을 폐쇄
// 개별 치킨집이 선택되는 기준: 개별 집으로부터의 치킨거리가 더 짧으면 선택, 같으면 둘 다 선택

int N, M, C;
int city[52][52];
map<pair<int,int>, int> cnt;
vector<pair<int, int>> house;

int Manhattan(int x1, int x2, int y1, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> city[i][j];

            if (city[i][j] == 2) { 
                cnt[{i, j}] = 0; 
                C++;
            }
            if (city[i][j] == 1) { house.push_back({i, j}); }
        }
    }
    
    // 개별 치킨집이 선택되는 횟수 count
    for (int i=0;i<(int)house.size();i++) {
        int min = INT_MAX;
        map<pair<int, int>, int> dist;
        for (auto itr=cnt.begin();itr!=cnt.end();itr++) {
            int house_X = house[i].first;
            int house_Y = house[i].second;
            int chicken_X = itr->first.first;
            int chicken_Y = itr->first.second;
            int l1 = Manhattan(house_X, chicken_X, house_Y, chicken_Y);
            dist[{chicken_X, chicken_Y}] = l1;
            if (min > l1) { min = l1; }
        }
        
        for (auto itr=dist.begin();itr!=dist.end();itr++) {
            if (itr->second == min) {
                int min_X = itr->first.first;
                int min_Y = itr->first.second;
                cnt[{min_X, min_Y}]++;
            }
        }
    }
    
    
    // 최소 거리의 합
    // count가 0이 아닌 치킨집 개수 세기
    // int open = 0;
    // for (auto itr=cnt.begin();itr!=cnt.end();itr++) {
    //     if (itr->second != 0) { open++; }
    // }
    
    // 만일 살아있는 치킨집이 M보다 작거나 같은 경우
    int sum = 0;
    if (M > 1) {
        for (int i=0;i<(int)house.size();i++) {
            int min = INT_MAX;
            for (auto itr=cnt.begin();itr!=cnt.end();itr++) {
                if (itr->second == 0) { continue; }
                int house_X = house[i].first;
                int house_Y = house[i].second;
                int chicken_X = itr->first.first;
                int chicken_Y = itr->first.second;
                int l1 = Manhattan(house_X, chicken_X, house_Y, chicken_Y);
                if (min > l1) { min = l1; }
            }
            sum += min;
        }
    }
    // otherwise
    else {
        vector<int> dist_vec;
        for (auto itr=cnt.begin();itr!=cnt.end();itr++) {
            int c_dist = 0; // 개별 치킨집에서 가구까지의 거리 
            for (int i=0;i<(int)house.size();i++) {
                c_dist += Manhattan(house[i].first, itr->first.first, house[i].second, itr->first.second);
            }
            dist_vec.push_back(c_dist);
        }
        sort(dist_vec.begin(), dist_vec.end());
        
        sum = dist_vec[0];
        // for (int i=0;i<M;i++) {
        //     sum += dist_vec[i];
        // }
    }
    cout << sum << "\n";
    return 0;
}