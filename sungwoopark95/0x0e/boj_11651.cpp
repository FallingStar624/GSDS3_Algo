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
        coord[y].push_back(x);
    }
    
    for (auto itr=coord.begin();itr!=coord.end();itr++) {
        vector<int> xs = itr->second;
        sort(xs.begin(), xs.end());
        for (int i=0;i<(int)xs.size();i++) {
            cout << xs[i] << " " << itr->first << "\n";
        }
    }
    
    return 0;
}