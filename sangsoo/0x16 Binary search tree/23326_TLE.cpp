// TLE
#include <iostream>
using namespace std;
int arr[500002];
int N, Q;
int d;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < Q; i++){
        int op;
        cin >> op;
        if (op == 1){
            int op1;
            cin >> op1;
            if (arr[op1-1] == 0) arr[op1-1] = 1;
            else arr[op1-1] = 0;

        }
        else if (op == 2){
            int op2;
            cin >> op2;
            d = (d+op2) % N;
        }
        else{
            int flag = 0;
            for(int j = 0; j < N; j++){
                if (arr[(d+j)%N] == 1){
                    cout << j << '\n';
                    flag = 1;
                    break;
                }
            }
            if(!flag) cout << -1 << '\n'; 
        }
    }

}