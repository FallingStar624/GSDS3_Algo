//failed
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    cin >> N >> L;
    deque <int> dq;
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        dq.push_back(tmp);
    }
    for (int i = 0; i < N; i++){
        int mn = 5000001;
        for (int j = 0 ;j < L; j ++){
            if ((i-L+1+j>=0) && (mn > dq[i-L+1+j])){
                mn = dq[i-L+1+j];
            }
        }
        cout << mn << " ";
    }
}
