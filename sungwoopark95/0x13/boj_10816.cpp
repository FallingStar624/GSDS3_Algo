#include <iostream>
#include <algorithm>
#define MAX 20000004
#define BASE 10000000
using namespace std;

int N, M;
int arr[500005];
int hash_table[MAX];

bool search(int* arr, int start, int end, int target) {
    int mid = start + ((end-start)/2);
    if (start <= end) {
        if (arr[mid] == target) { 
            return true; 
        } else if (arr[mid] < target) {
            return search(arr, mid+1, end, target);
        } else {
            return search(arr, start, mid-1, target);
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    int idx = 0;
    while (N--) {
        int temp;
        cin >> temp;
        if (hash_table[temp+BASE] == 0) { arr[idx++] = temp; }
        hash_table[temp+BASE]++;
    }
    
    sort(arr, arr+idx);
    
    cin >> M;
    while (M--) {
        int target;
        cin >> target;
        if (search(arr, 0, idx-1, target)) { 
            cout << hash_table[target+BASE] << " "; 
        } else {
            cout << 0 << " ";
        }
    }
    cout << "\n";
    return 0;
}