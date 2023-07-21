#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <string.h>
#include <unordered_set>

using namespace std;

unordered_set<string> s;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string name, log;
        cin >> name >> log;
        if(log == "enter")
            s.insert(name);
        else
            s.erase(name);
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto x: ans)
        cout << x << '\n';

    return 0;
}