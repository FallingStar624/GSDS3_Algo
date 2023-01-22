#include <iostream>
#include <vector>
using namespace std;

vector<int> divisor(int n) {
    vector<int> div;
    for(int i = 0; i <= n; i++){
        if(n % i == 0) div.push_back(i);
    }
    return div;
}