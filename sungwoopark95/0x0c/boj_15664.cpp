#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M;
int arr[10];
int seq[10];
bool isused[10];
set<vector<int>> s;

void func(int cur) {
    if (cur == M) {
        vector<int> vec;
        for (int i=0;i<M;i++) { vec.push_back(arr[i]); }
        s.insert(vec);
        return;
    }
    
    for (int i=0;i<N;i++) {
        if (!isused[i]) {
            if (cur>=1 && arr[cur-1] > seq[i]) { continue; }
            arr[cur] = seq[i];
            isused[i] = 1;
            func(cur+1);
            isused[i] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> seq[i];
    }
    sort(seq, seq+N);
    
    func(0);
    for (auto itr=s.begin();itr!=s.end();itr++) {
        vector<int> item = *itr;
        for (int i=0;i<(int)item.size();i++) {
            cout << item[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}