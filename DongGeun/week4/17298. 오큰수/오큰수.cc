#include <bits/stdc++.h>
using namespace std;

int N,K;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int arr[N],res[N];
    for (int i=0;i<N;i++)
    {
        cin >> K;
        arr[i]=K;
        res[i]=-1;
    }
    stack<int> S;
    for (int i=0;i<N;i++) {
        while(!S.empty()&&arr[S.top()]<arr[i])
        {
            res[S.top()]=arr[i];
            S.pop();

        }
        S.push(i);
    }
    for (int i=0;i<N;i++) {cout<<res[i]<<' ';}
}

