#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> count(26);
    for (int i=0; i<str.size(); i++) {
        char temp = str[i];
        count[int(temp)-97] += 1;
    }
    for (int i=0; i<26; i++) cout << count[i] << ' ' ;
    return 0;
}
