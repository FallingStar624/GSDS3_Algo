#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a;
    int b;
    for(int i=0; i<n; i++){
    cin >> a >> b;
    v.push_back(pair<int, int>(a, b));
    }
    sort(v.begin(), v.end(), compare);

    for(int i=0; i<n; i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }

}