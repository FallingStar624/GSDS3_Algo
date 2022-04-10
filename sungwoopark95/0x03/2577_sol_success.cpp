#include <bits/stdc++.h>
using namespace std;

unsigned int count_zero(string str);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // get the inputs
    int A, B, C;
    cin >> A >> B >> C;

    // multiply all of them and convert into string
    int mul = A * B * C;
    string mul_str = to_string(mul);

    // print the number of zeros
    unsigned int zeros = count_zero(mul_str);
    cout << zeros << "\n";

    // prepare for the digit counts
    char digits[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; 
    int digit_count[9];
    
    // initialize the array
    for (int i=0;i<9;i++) {
        digit_count[i] = 0;
    }

    // count the digits
    for (int k=0;k<9;k++) {
        for (int j=0;j<(int)mul_str.length();j++) {
            if (mul_str[j] == digits[k]) {
                digit_count[k] += 1;
            }
        }
        cout << digit_count[k] << "\n";
    }

    return 0;
}

unsigned int count_zero(string str) {
    int zeros = 0;
    for (int i=0;i<(int)str.length();i++) { // str.length() -> long; type casting 필요
        if (str[i] == '0') {
            zeros += 1;
        }
    }
    return zeros;
}