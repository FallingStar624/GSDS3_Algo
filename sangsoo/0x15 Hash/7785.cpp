#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    unordered_map<string, string> m;
    for(int i = 0; i < n; i++){
        string name, el;
        cin >> name >> el;
        m[name] = el;
    }
    vector<string> v;
    for(auto e : m){
        if (e.second == "enter"){
            v.push_back(e.first);
        }
    }
    sort(v.rbegin(), v.rend()); // 역순 정렬
    for(auto e : v) cout << e << "\n";
}
