#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[52];
int B[52];
int C[52];
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int i = 0; i < n; i++){
        cin >> B[i];
    }
    sort(A, A+n);
    sort(B, B+n);
    reverse(B, B+n);
    int out = 0;
    for (int i = 0; i < n; i++){
        C[i] = A[i]*B[i];
    }
    for(int i = 0; i < n; i++){
        out += C[i];
    }
    cout << out;
}