#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int K, L;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second; // 앞에꺼가 뒤에꺼 보다 작게 -> 오름차순
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> L;
    unordered_map<string, int> m;
    for(int i = 0; i < L; i++){
        string id;
        cin >> id;
        m[id] = i;
    }
    vector <pair<string, int>> v;
    for(auto e: m){
        v.push_back({e.first, e.second});
    }
    sort(v.begin(), v.end(), cmp);
    int s = (v.size() < K) ? v.size() : K; // edge case 대비, 같은 사람이 여려번 들어왔을 경우
    for(int i = 0; i < s; i++){
        cout << v[i].first << '\n';
    }
}
