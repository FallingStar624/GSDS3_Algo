// # = N (<=10,000,000), ascending order
// 그 아래 수 차례로 주어짐 (<=10,000)

// counting sort

#include <iostream>
//#include <vector>
#include <algorithm>
//#include <climits>
//#include <bits/stdc++.h>
using namespace std;
 
int n, num;
int seq[10001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> num;//seq[i];
        seq[num]+=1;
    }

    for (int i=1; i<10001; i++){
        for (int j=0; j<seq[i]; j++){
            cout << i << '\n';
        }
    }
    
    return 0;
}

// sort with vector [10000000]: 공간 복잡도 메모리 초과
// O(N^2): 시간 복잡도 초과
// https://tooo1.tistory.com/72