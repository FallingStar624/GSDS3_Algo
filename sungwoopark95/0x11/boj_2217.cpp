#include <iostream>
#include <algorithm>
#define MAX 100005
using namespace std;

int N, maximum;
int ropes[MAX];
int answer[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=1;i<=N;i++) { cin >> ropes[i]; }
    
    sort(ropes+1, ropes+N+1);
    
    for (int i=N;i>=1;i--) {
        answer[N-i+1] = ropes[i] * (N-i+1);
        if (maximum < answer[N-i+1]) { maximum = answer[N-i+1]; }
    }
    
    cout << maximum << "\n";
    
    return 0;
}