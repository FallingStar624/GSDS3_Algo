#include <iostream>
#include <vector>
using namespace std;

int num = 0;
vector<bool> state(1000001, true);
void solve(int n){
    state[1] = false;
    for(int i=2; i*i <=n; ++i){
        if(!state[i]) continue;
        for(int j= i*i; j<=n; j+=i)
            state[j] = false;
    }
}

int main(){
    int m,n; cin >>m>>n;
    solve(n);
    for(int i=m; i<=n; ++i){
        if(state[i]) cout << i <<"\n";
    }
}