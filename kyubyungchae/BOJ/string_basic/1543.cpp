#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string t, p;

    getline(cin, t);
    getline(cin, p);
    int cnt = 0; 
    int f = t.find(p);

    while(f != string::npos){
        cnt++;
        f = t.find(p, f + p.size());
    }
    cout << cnt;
}