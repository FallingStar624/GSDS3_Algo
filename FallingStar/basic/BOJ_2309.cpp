#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> v(9);
    for (int i=0; i <9; i++) {
        int tmp;
        cin >> tmp;
        v[i]=tmp;
    }
    sort(v.begin(), v.end());
    int total = accumulate(v.begin(), v.end(), 0);
    int target = total - 100;
    for (int i=0; i < 9; i++)
        for (int j=i+1; j<9; j++)
        {
            if (v[i]+v[j]==target) {
                for (int k=0; k < 9; k++) {
                    if (k != i and k != j) cout << v[k] << "\n";
                }
                exit(EXIT_SUCCESS);
            }
        }
    return 0;
}
