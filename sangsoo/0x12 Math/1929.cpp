#include <bits/stdc++.h>
using namespace std;
int n, m;
int isprime(int x){
    if (x == 1) return 0;
    for(int i=2; i*i<=x; i++){
        if (x % i == 0) return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> m >> n;
    for(int i = m; i <= n; i++){
        if(isprime(i)) cout << i << '\n';
    }

}