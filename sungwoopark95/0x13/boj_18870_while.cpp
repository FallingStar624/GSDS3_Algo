#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N;
int arrcpy[1000003];
int arr[1000003];
map<int, int> isused;

int search(int* arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + ((end-start)/2);
        // 정렬했을 때의 위치를 반환
        if (arr[mid] == target) { return mid; } 
        else if (arr[mid] < target) { start = mid + 1; } 
        else { end = mid - 1; }
    }
    // 없는 경우
    return -1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    int idx = 0;
    for (int i=0;i<N;i++) {
        int temp;
        cin >> temp;
        if (isused[temp] == 0) { 
            isused[temp]++; 
            arr[idx++] = temp;
        }
        arrcpy[i] = temp;
    }
    
    sort(arr, arr+idx);

    for (int i=0;i<N;i++) {
        cout << search(arr, 0, idx-1, arrcpy[i]) << " ";
    }
    cout << "\n";
    
    return 0;
}