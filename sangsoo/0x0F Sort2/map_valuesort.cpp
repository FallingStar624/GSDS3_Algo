// https://notepad96.tistory.com/56
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int main(){
    map<int, int> map;
    map[5]= 20;
    map[2] = 50;
    map[3] = 10;
    map[4] = 40;
    map[1] = 30;
    map[6] = 60;

    for (auto it : map){
        cout << it.first << " " << it.second << " ";
    }
    cout << "\n=============================\n";

    vector<pair<int, int>> v(map.begin(), map.end());
    for(pair<int, int> it : v) cout << it.first << " " << it.second << " ";

    cout << "\n=============================\n";

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
        });
    for (pair<int, int> it : v) cout << it.first << " " << it.second << " ";

    cout << "\n=============================\n";
    return 0;
}