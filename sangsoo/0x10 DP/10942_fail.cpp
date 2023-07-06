// Time limit exceeded
#include <bits/stdc++.h>
using namespace std;

int arr[2002];
int N, S, E, M;

int func(int s, int e){
    int cnt = 0;
    int sp = s; int rp = e;
    while(sp < rp){
        if (arr[sp-1] != arr[rp-1]){
            return 0;
        }
        sp++; rp--;
    }
    return 1;

}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++){
        cin >> S >> E;
        if (func(S, E)) cout << "1" << '\n';
        else cout << "0" << '\n';
    }
    return 0;
}