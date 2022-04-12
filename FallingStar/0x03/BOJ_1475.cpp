#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> count(10);
    for (char s: str) count[int(s)-48]++;
    int replacement = ceil(float(count[6]+count[9])/2);
    count[6] = count[9] = replacement;
    int maximum = 0;
    for (int i: count) {
        if (i>maximum) maximum=i;
        else continue;
    }
    cout << maximum;
    return 0;
}
