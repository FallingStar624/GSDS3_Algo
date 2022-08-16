#include <iostream>
using namespace std;
// 8 7 3 1 1 vs 6 3 1
// 13 7 2 vs 290 215 103 11

int T, N, M;
int A[20002], B[20002];

void Merge(int* arr, int start, int mid, int last) {
    int k = start; 
    int len1 = (mid+1) - start; 
    int len2 = last - mid;
    int sub1[len1], sub2[len2];
    
    for (int i=0;i<len1;i++) { sub1[i] = arr[start+i]; }
    for (int j=0;j<len2;j++) { sub2[j] = arr[mid+1+j]; }
    
    int m = 0; int l = 0;    
    while (m < len1 && l < len2) {
        if (sub1[m] > sub2[l]) { arr[k] = sub1[m++]; } 
        else { arr[k] = sub2[l++]; }
        k++;
    }
    
    if (m == len1) {
        for (int x=l;x<len2;x++) { arr[k++] = sub2[x]; }
    } else {
        for (int x=m;x<len1;x++) { arr[k++] = sub1[x]; }
    }
    
}

void MergeHelp(int* arr, int start, int last) {
    if (start == last) { return; }
    int mid = (start+last) / 2;
    MergeHelp(arr, start, mid);
    MergeHelp(arr, mid+1, last);
    Merge(arr, start, mid, last);
}

void MergeSort(int* arr, int len) {
    MergeHelp(arr, 0, len-1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> N >> M;
        
        for (int i=0;i<N;i++) { cin >> A[i]; }
        for (int i=0;i<M;i++) { cin >> B[i]; }
        
        MergeSort(A, N);
        MergeSort(B, M);

        int k = 0, sum = 0;
        for (int i=0;i<N;i++) {
            if (A[i] > B[k]) { sum += M; }
            else {
                while (A[i] <= B[k] && M > 0) {
                    k++; M--;
                }
                sum += M;
            }
        }
        cout << sum << "\n";
    }
    
    return 0;
}