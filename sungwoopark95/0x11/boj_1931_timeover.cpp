#include <iostream>
#include <algorithm>
using namespace std;

int N, max_meetings;
pair<long, pair<long, long>> arr[100005];
int answer[100005];

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
        int meetings = 0; int endtime = 0;
        for (int j=i;j<=N;j++) {
            if (j == i) {
                meetings++;
                endtime = arr[j].second.second;
            } else {
                if (arr[j].second.first >= endtime) {
                    meetings++;
                    endtime = arr[j].second.second;
                }
            }
        }
        answer[i] = meetings;
        if (max_meetings < answer[i]) { max_meetings = answer[i]; }
    }
    
    cout << max_meetings << "\n";

    return 0;
}