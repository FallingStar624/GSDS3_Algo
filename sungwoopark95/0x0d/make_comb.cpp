#include <iostream>
#include <vector>
using namespace std;

// int N, M;
int arr[10];
bool isused[10];
vector<vector<int>> combs;

void MakeComb(int cur, int N, int M) {
    if (cur == M) {
        vector<int> idx;
        for (int i=0;i<M;i++) { 
            idx.push_back(arr[i]); 
        }
        combs.push_back(idx);
        return;
    }
    
    for (int i=0;i<N;i++) {
        if(!isused[i]) {
            if (cur >= 1 && arr[cur-1] > i) { continue; }
            arr[cur] = i;
            isused[i] = 1;
            MakeComb(cur+1, N, M);
            isused[i] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    MakeComb(0, 5, 3);
    vector<pair<int, int>> address;
    address.push_back({1, 1});
    address.push_back({2, 3});
    address.push_back({1, 4});
    address.push_back({4, 2});
    address.push_back({5, 3});
    
    for (int i=0;i<(int)combs.size();i++) {
        for (int j=0;j<(int)combs[i].size();j++) {
            pair<int, int> item = address[combs[i][j]];
            cout << "(" << item.first << "," << item.second << ")" << " ";
        }
        cout << "\n";
    }
    
    return 0;
}