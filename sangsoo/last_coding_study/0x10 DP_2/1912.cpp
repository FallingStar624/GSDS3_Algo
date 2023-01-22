#include <iostream>
using namespace std;

int int_arr[100002];
int cumul[100002];
int mx =0;

/*
algorithm
if cumul[i-1] > 0 -> "cumulation" cumul[i] = cumul[i-1] +int_arr[i]
if cumul[i-1] < 0 -> "fresh start" cumul[i] = int_arr[i]  
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> int_arr[i];
    }

    cumul[0] = int_arr[0];
    mx = cumul[0];
    for(int i = 1; i < n; i++){
        if(cumul[i-1] > 0){
            cumul[i] = cumul[i-1] + int_arr[i];
        }
        else{
            cumul[i] = int_arr[i];
        }
            if(mx < cumul[i]){
                mx = cumul[i];
            }
        
    }
    cout << mx;
}