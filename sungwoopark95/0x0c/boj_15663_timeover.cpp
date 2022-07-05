#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[10];
int seq[10];
bool isused[10];
vector<vector<int>> vecvec;
int cnt = 0;

void func(int cur) {
    if (cur == M) {
        vector<int> vec;
        for (int i=0;i<M;i++) { 
            vec.push_back(arr[i]);
        }
        if (find(vecvec.begin(), vecvec.end(), vec) == vecvec.end()) { 
            vecvec.push_back(vec); 
        }
        return;
    }
    
    for (int i=0;i<N;i++) {
        if (!isused[i]) {
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

    for (int i=0;i<vecvec.size();i++) {
        for (int j=0;j<vecvec[i].size();j++) {
            cout << vecvec[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}