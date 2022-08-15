#include <iostream>
#include <vector>
using namespace std;

struct Operation {
    int cnt;
    vector<int> visited;
};

int N;
Operation D[1000005];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    D[1].cnt = 0;
    D[1].visited.push_back(1);
    
    for (int i=2;i<=N;i++) {
        int m = D[i-1].cnt + 1;
        int k = i - 1;
        if (i%2 == 0) {
            if (m > D[i/2].cnt+1) {
                m = D[i/2].cnt+1;
                k = i / 2;
            }
        }
        if (i%3 == 0) {
            if (m > D[i/3].cnt+1) {
                m = D[i/3].cnt + 1;
                k = i / 3;
            }
        }
        
        D[i].cnt = m;
        D[i].visited = D[k].visited;
        D[i].visited.push_back(i);
    }
    
    cout << D[N].cnt << "\n";
    for (int i=(int)D[N].visited.size()-1;i>=0;i--) {
        cout << D[N].visited[i] << " ";
    }
    cout << "\n";
    
    return 0;
}