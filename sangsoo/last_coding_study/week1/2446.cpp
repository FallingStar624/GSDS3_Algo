#include <iostream>
using namespace std;
int n;
int m;
int main(){
    cin >> n;
    for(int row = 1 ; row <= n; row++){
        for(int i = 0; i < row-1; i++){
            cout << " ";
        }
        for(int i = 0; i < 2*n-2*row+1; i++){
            cout << "*";
        }

        cout << "\n";
    }
    m = n-1;
    for(int row = 1; row <=m; row++){
        for(int i =0; i < m-row; i++){
            cout << " ";
        }
        for(int i =0; i< 2*row+1 ;i++){
            cout << "*";
        }
        cout <<"\n";
    }
}