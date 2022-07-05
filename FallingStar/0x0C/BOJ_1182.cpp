#include <iostream>
#include <vector>
using namespace std;
int n, s, cnt=0;
int sub[21];

void back_track(int limit, vector<int> visit) {
    if (visit.size()==limit) {
        int tmp = 0;
        for (int i: visit) {
            tmp += sub[i];
        }
        if (tmp == s) cnt++;
        return;
    }
    for (int j=1; j<n+1; ++j) {
        if (!visit.empty() && visit.back()<j) {
            visit.push_back(j);
            back_track(limit, visit);
            visit.pop_back();
        } else if (visit.empty()) {
            visit.push_back(j);
            back_track(limit, visit);
            visit.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int k=1; k<n+1; ++k) {
        cin >> sub[k];
    }
    vector<int> start;
    for (int k=1; k<n+1; ++k) {
        back_track(k, start);
    }
    cout << cnt;
    return 0;
}
