#include <bits/stdc++.h>
using namespace std;

int N, S;
int st, en;
int arr[100002];
int prefixsum[100002];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for(int i = 0 ; i < N; i++) {
        cin >> arr[i];
    }
    int mn = 1e5+1;
    prefixsum[0] = arr[0];
    for(int i = 1; i < N; i++){
        prefixsum[i] = arr[i] + prefixsum[i-1];
    }
    while(st < N){
        while(en < N){
            if(prefixsum[en]-prefixsum[st-1] >= S){
                mn = min(mn, en-st);
                break;
            }
            en++;
        }
        st++;
    }
    if (mn == 1e5+1) {cout << 0; return 0;}
    cout << mn+1;
}