#include <iostream>
using namespace std;
int n;
int m;
int main(){
    cin >> n;
    for(int row = 1 ; row <= n-1; row++){
        for(int i = 0; i < row; i++){
            cout << "*";
        }
        for(int i = 0; i < 2*n-2*row-1; i++){
            cout << " ";
        }
        for(int i = 0; i < row; i++){
            cout << "*";
        }
        cout << "\n";
    }
    for(int i = 0 ; i <2*n-1 ; i++){
        cout << "*";
    }
    cout <<"\n";
    m = n-1;
    for(int row = 1; row <=m; row++){
        for(int i =0; i < m-row+1; i++){
            cout << "*";
        }
        for(int i =0; i< 2*row-1 ;i++){
            cout << " ";
        }
        for(int i =0; i < m-row+1; i++){
            cout << "*";
        }
        cout <<"\n";
    }
}