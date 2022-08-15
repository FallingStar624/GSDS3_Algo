#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, c;
vector<pair<int,int>> arr; // {cnt, num}

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        bool isIn = false; 
        for(pair<int,int> &p : arr) {
            if(p.second == num) {
                isIn = true;
                p.first++;
                break;
            }
        }
        if(!isIn) {
            arr.push_back({1, num});
        }
    }
    stable_sort(arr.begin(), arr.end(), cmp);

    for(pair<int,int> p : arr) {
        while(p.first--) {
            cout << p.second << ' ';
        }
    }
    return 0;
}