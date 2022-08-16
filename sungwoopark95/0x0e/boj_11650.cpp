#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N;
map<int, vector<int>> coord;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        int x, y;
        cin >> x >> y;
        coord[x].push_back(y);
    }
    
    for (auto itr=coord.begin();itr!=coord.end();itr++) {
        vector<int> ys = itr->second;
        sort(ys.begin(), ys.end());
        for (int i=0;i<(int)ys.size();i++) {
            cout << itr->first << " " << ys[i] << "\n";
        }
    }
    
    return 0;
}