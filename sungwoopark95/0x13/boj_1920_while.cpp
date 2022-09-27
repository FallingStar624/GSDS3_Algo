#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100005];

int search(int* arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + ((end-start)/2);
        if (arr[mid] == target) { return 1; } 
        else if (arr[mid] < target) { start = mid + 1; } 
        else { end = mid - 1; }
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) { cin >> arr[i]; }
    sort(arr, arr+N);
    
    cin >> M;
    int target;
    while (M--) {
        cin >> target;
        cout << search(arr, 0, N-1, target) << "\n";
    }
    
    return 0;
}