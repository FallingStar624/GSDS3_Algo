#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
map<int, vector<string>> list;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        int age; string name;
        cin >> age;
        cin >> name;
        list[age].push_back(name);
    }
    
    for (auto itr=list.begin();itr!=list.end();itr++) {
        vector<string> names = itr->second;
        for (int i=0;i<(int)names.size();i++) {
            cout << itr->first << " " << names[i] << "\n";
        }
    }
    
    return 0;
}