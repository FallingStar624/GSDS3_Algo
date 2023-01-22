#include <iostream>
using namespace std;
int n;
int main(){
    cin >> n;
    for(int row = 1 ; row <= n; row++){
        for(int i = 0; i < row-1; i++){
            cout << " ";
        }
        for(int i = 0; i <n-row+1; i++){
            cout << "*";
        }
        cout << "\n";
    }
}