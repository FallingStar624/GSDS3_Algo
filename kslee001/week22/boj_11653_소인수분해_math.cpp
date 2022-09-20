#include <iostream>
#include <vector>
using namespace std;

void solve(int n){
    int target = n;
    for(int i=2; i<=n; ++i)
        if(target%i ==0)
            while(target%i == 0){
                target/=i;
                cout << i <<"\n";
            }
}

int main(){
    int n; cin >>n;
    if(n == 1){
        return 0;
    }
    solve(n);
}