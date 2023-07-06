#include <bits/stdc++.h>
using namespace std;
int n;
int isprime(int x){
    if (x == 1) return false;
    for(int i=2; i*i<=x; i++){
        if (x % i == 0) return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(isprime(tmp)) cnt++;
    }
    cout << cnt;

}