#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    vector<int> count(26);
    for (char i: str1) count[int(i)-97]++;
    for (char j: str2) count[int(j)-97]--;
    int result = 0;
    for (int m: count) result += m>0 ? m: -m;
    cout << result;
    return 0;
}
