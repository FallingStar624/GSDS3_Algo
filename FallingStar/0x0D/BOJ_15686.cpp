#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m; // n: 크기, m: 점포 수
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int dist[13][100]; // i번째 치킨집으로부터 j번째 집까지의 거리
int dist2[100]; // i번째 집의 최소 치킨거리
int ans=987654321;

int measure_dist(pair<int, int> c, pair<int, int> h) {
    int distance = abs(c.first-h.first) + abs(c.second-h.second);
    return distance;
}

void update_dist(int idx) {
    for (int i=0; i<houses.size(); i++) {
        dist2[i] = min(dist2[i], dist[idx][i]);
    }
}

void reset_dist2() {
    for (int i=0; i<houses.size(); i++) {
        dist2[i] = 200;
    }
}

bool check_m(string target) {
    int cnt=0;
    for (char c: target) {
        if (c=='1') cnt++;
    }
    if (cnt>m) return false;
    return true;
}

void back_track(string cur) {
    if (!check_m(cur)) {
        return;
    }
    if (cur.size()==chickens.size()) {
        if (check_m(cur)) {
            reset_dist2();
            for (int i=0; i<chickens.size(); i++) {
                if (cur[i]=='1') {
                    update_dist(i);
                };
            }
            int tmp=0;
            for (int i=0; i<houses.size(); i++) {
                tmp += dist2[i];
            }
            ans = min(ans, tmp);
        }
        return;
    } else {
        back_track(cur+ to_string(0));
        back_track(cur+ to_string(1));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n ;j++) {
            int tmp;
            cin >> tmp;
            if (tmp==1) {
                houses.push_back({i, j});
            } else if (tmp==2) {
                chickens.push_back({i, j});
            }
        }
    }
    //각 집들과 치킨집들 사이의 거리 측정
    for (int i=0; i<chickens.size(); i++) {
        for (int j=0; j<houses.size(); j++) {
            dist[i][j] = measure_dist(chickens.at(i), houses.at(j));
        }
    }

    back_track("");
    cout << ans;
    return 0;
}
