#include <iostream>
#include <algorithm>
/*
algorithm
f(n,i) = min{f(n-1,i-1),f(n-1, i)} + g(n,i)
f : cumulative function
g : value function
*/

using namespace std;

int main(){
    int cumul[502][502];
    int value[502][502];
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> value[i][j];
        }
    }


    cumul[0][0] = value[0][0];
    cumul[1][0] = value[1][0]+value[0][0];
    cumul[1][1] = value[1][1]+value[0][0];




    for(int i=2; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j ==0){
                cumul[i][j] = cumul[i-1][j] + value[i][j];
            }
            else{
                cumul[i][j] = max(cumul[i-1][j-1], cumul[i-1][j]) + value[i][j];
            }
        }
    }
    int mx = 0;
    for(int i=0; i<n; i++){
        if(mx < cumul[n-1][i])
            mx = cumul[n-1][i];
    }    
    cout << mx;
}