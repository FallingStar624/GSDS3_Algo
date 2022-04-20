#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 1;
    int temp;
    for (int i=0; i<3; i++) {
        cin >> temp;
        num*=temp;
    }
    vector<int> count(10);
    while (num>=1) {
        int temp = num%10;
        num = num/10;
        count[temp]+=1;
    }
    for (int i: count) cout << i << '\n';
    return 0;
}
