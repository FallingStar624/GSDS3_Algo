#include <iostream>
using namespace std;

int main(){
    int n, k, out_numerator, out_denominator;
    out_numerator = 1;
    out_denominator = 1;
    cin >> n >> k;
    for(int i = n; i > n-k; i--){
        out_numerator *= i;
        out_numerator %= 10007;
    }
    for(int i = k; i > 0; i--){
        out_denominator *= i;
        out_denominator %= 10007;
    }
    cout << (out_numerator / out_denominator) % 10007;
}