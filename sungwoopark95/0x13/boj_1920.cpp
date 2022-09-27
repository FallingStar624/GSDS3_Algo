#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100005];

bool search(int* arr, int start, int end, int target) {
    int mid = start + ((end - start) / 2);
    if (start <= end) { // equivalent to start <= mid && end >= mid
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