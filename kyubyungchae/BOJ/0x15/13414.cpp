#include <iostream>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <math.h>
#include <vector>
#include <utility>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, l;
    cin >> k >> l;

    unordered_map<string, int> q{};

    for(int i = 0; i < l; ++i) {
        string snum;
        cin >> snum;
        if(q.find(snum) != q.end()) {
            q.erase(snum);
            q[snum] = i;
        } 
        else 
            q[snum] = i;
    } 

    vector<pair<string,int>> slist (q.begin(), q.end());
    sort(slist.begin(), slist.end(), [](auto& a, auto& b) { return a.second < b.second;});

    int en = min(k, (int)slist.size());

    for(int i = 0; i < en; ++i)
        cout << slist[i].first << '\n';

    return 0;
}