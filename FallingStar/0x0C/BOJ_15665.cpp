#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
string end_point;
vector<int> v;
int arr[10];

void back_track(string cur) {
    if (cur.length()==m) {
        for (char c: cur) {
            cout << arr[c-48] << " ";
        }
        if (cur!=end_point) cout << "\n";
        return;
    }
    for (int i=0; i<k; i++) {
        back_track(cur+to_string(i));
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    k = v.size();
    for (int i=0; i<v.size(); ++i) {
        arr[i] = v.at(i);
    }
    for (int i=0; i<k; ++i) {
        end_point += to_string(k);
    }
    back_track("");
    return 0;
}
