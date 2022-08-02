// # = N (<=1000), ascending order
// 그 아래 수 차례로 주어짐

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i=0; i<N; i++){
        cout << v[i] << '\n';
    }
    return 0;
}

// bubble & insert: https://blockdmask.tistory.com/90