#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> arr;
string stop;

void back_track(string visit) {
    if (visit.length()==m) {
        for (char c : visit) {
            cout << arr[c-'1'] << " ";
        }
        if (visit!=stop) {
            cout << "\n";
        }
        return;
    }
    for (int j=1; j<n+1; ++j) {
        bool check = true;
        for (char c : visit) {
            if (c-'0' > j){
                check=false;
            }
        }
        if (check) {
            back_track(visit+ to_string(j));
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    string start;
    for (int i=n; i>n-m; --i) {
        stop += to_string(n);
    }
    back_track(start);
    return 0;
}
