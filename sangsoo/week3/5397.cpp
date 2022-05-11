#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        list<char> L = {};
        auto cursor = L.begin();

        string pw;
        cin >> pw;

        for (auto c: pw){
            if (c == '<'){
                if(cursor != L.begin()) cursor--;
            }
            else if (c == '>'){
                if(cursor != L.end()) cursor++;
            }
            else if (c == '-'){
                if(cursor != L.begin()){
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else { // c가 문자
                L.insert(cursor, c);
            }
        }
    for (auto c : L){
        cout << c;
    }
    cout << '\n';
    }
    return 0;
}