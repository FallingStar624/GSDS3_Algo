#include <iostream>
#include <map>
using namespace std;

int N, M;
map<int, int> hash_table;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while (N--) {
        int temp;
        cin >> temp;
        hash_table[temp]++;
    }
    
    cin >> M;
    while (M--) {
        int target;
        cin >> target;
        cout << hash_table[target] << " ";
    }
    cout << "\n";
    return 0;
}