#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100002];
int st, en;
int mn;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    st = 0; en = 0; mn = 2e9+1;
    sort(arr, arr+N);
    while(st < N){
        while(en < N){
            if(arr[en] - arr[st] >= M){
                mn = min(mn, arr[en]-arr[st]); // min으로 해줘야함.
                break;
            }
            else
                en++;
        }
        st++;
    }
    cout << mn;
}

/*

왜 아래와 같은 식으로 하면 틀릴까???? :(

int N, M;
int arr[100002];
int st, en;
int mn;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    st = 0; en = 0; mn = 2e9;
    sort(arr, arr+N);
    while(st < N){
        while(en < N){
            if(arr[en] - arr[st] >= M && arr[en] - arr[st] < mn){
                mn = arr[en]-arr[st];
                break;
            }
            else
                en++;
        }
        st++;
    }
    cout << mn;
}


*/