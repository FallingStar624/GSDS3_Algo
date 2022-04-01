#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int total = 0;
    vector<int> v(5);

    for (int i=0; i<5; i++) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
        total += tmp;
    }
    sort(v.begin(), v.end());
    cout << total/5 << "\n" << v[2];
}

