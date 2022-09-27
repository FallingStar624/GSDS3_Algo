#include <iostream>
#define MAX 20000004
#define BASE 10000000
using namespace std;

int N, M;
int hash_table[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while (N--) {
        int temp;
        cin >> temp;
        hash_table[temp+BASE]++;
    }
    
    cin >> M;
    while (M--) {
        int target;
        cin >> target;
        cout << hash_table[target+BASE] << " ";
    }
    cout << "\n";
    return 0;
}