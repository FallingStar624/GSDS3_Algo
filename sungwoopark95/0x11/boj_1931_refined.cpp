#include <iostream>
#include <algorithm>
using namespace std;

int N, max_meetings;
pair<long, long> arr[100005];
pair<long, long> schedule[100005];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=1;i<=N;i++) {
        int start, end, total;
        cin >> start >> end;
        total = start + end;
        arr[i] = make_pair(total, end);
        schedule[i] = make_pair(end, start);
    }
    
    sort(arr+1, arr+N+1);
    sort(schedule+1, schedule+N+1);

    max_meetings = 1;
    int endtime = arr[1].second;
    for (int i=2;i<=N;i++) {
        if (schedule[i].second >= endtime) {
            max_meetings++;
            endtime = schedule[i].first;
        }
    }
    
    cout << max_meetings << "\n";

    return 0;
}