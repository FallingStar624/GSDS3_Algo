// 문제 해결 못함 //
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int k;
    cin >> n >> k;

    list <int> L;

    for (int i = 1 ; i <= n ; i++){
        L.push_back(i);
    }
    auto cursor = L.begin();
    
    cout << '<';

    while (L.size()>1){
        for (int i = 0; i < k-1 ; i++){
            cursor ++;
            if(cursor == L.end()){
                cursor = L.begin();
            }
        }
    }

    cout << *cursor <<", ";
    cursor = L.erase();

    if (cursor == L.end()){
        cursor == L.begin();
    }
    cout << *cursor << '>';
    return 0;

}

