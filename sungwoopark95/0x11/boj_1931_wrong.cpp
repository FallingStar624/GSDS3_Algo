#include <iostream>
#include <algorithm>
using namespace std;

int N, endtime, meetings;
pair<int, pair<int, int>> arr[100005];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=1;i<=N;i++) {
        int start, end, total;
        cin >> start >> end;
        total = start + end;
        arr[i] = make_pair(total, make_pair(start, end));
    }
    
    sort(arr+1, arr+N+1);

    for (int i=1;i<=N;i++) {
        if (i == 1) {
            meetings++;
            endtime = arr[i].second.second;
        } else {
            if (arr[i].second.first >= endtime) {
                meetings++;
                endtime = arr[i].second.second;
            }
        }
    }
    cout << meetings << "\n";
    
    return 0;
}