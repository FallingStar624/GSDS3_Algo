#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int n, m;
int city[51][51];

struct store {
    int x, y;
    bool isClosed = false;
};
struct house {
    int x, y;
};
store stores[14];
house houses[101];
store arr[14];
bool isused[14];

int cnt_store;
int cnt_house;
int ans = INT_MAX;

int CalcDist(int rx, int ry, int dx, int dy) {
    return abs(dx - rx) + abs(dy - ry);
}

int GetDist() {
    int dist = 0;
    for(int i = 0; i < cnt_house; i++) {
        int min_dist = INT_MAX;
        for(int j = 0; j < cnt_store; j++) {
            int d = CalcDist(houses[i].x, houses[i].y, s.x, s.y);
            min_dist = min(min_dist, d);
        }
        dist += min_dist;
    }
    return dist;
}

void Func(int idx_store) {

    if(idx_store == m) {
        int tot_dist = GetDist();
        ans = min(ans, tot_dist);
        return;
    }

    for(int i = 0; i < cnt_store; i++) {
        if(!isused[i]) {
            arr[idx_store] = stores[i];
            isused[i] = 1;
            Func(idx_store+1);
            isused[i] = 0;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> city[i][j];
            if(city[i][j] == 2) {
                stores[cnt_store].x = i;
                stores[cnt_store++].y = j;
            }
            if(city[i][j] == 1) {
                houses[cnt_house].x = i;
                houses[cnt_house++].y = j;
            }

        }
    }

    Func(1);

    return 0;
}