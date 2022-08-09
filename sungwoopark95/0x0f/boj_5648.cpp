#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
long arr[2000002];
long reverse(string& x);
void MergeSort(long* arr, int len);
void MergeHelp(long* arr, int start, int last);
void Merge(long* arr, int start, int mid, int last);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        string temp;
        cin >> temp;
        arr[i] = reverse(temp);
    }
    
    MergeSort(arr, N);

    for (int i=0;i<N;i++) {
        cout << arr[i] << "\n";
    }
    
    return 0;
}

long reverse(string& x) {
    int i = x.length()-1;
    while (x[i] == '0') {
        i--;
        continue;
    }
    
    string rev = "";
    for (int j=i;j>=0;j--) {
        rev += x[j];
    }
    
    if (rev.length() == 0) { rev = '0'; }
    
    return stol(rev);
}

void MergeSort(long* arr, int len) {
    MergeHelp(arr, 0, len-1);
}

void MergeHelp(long* arr, int start, int last) {
    if (start == last) { return; }
    int mid = start + ((last-start)/2);
    MergeHelp(arr, start, mid);
    MergeHelp(arr, mid+1, last);
    Merge(arr, start, mid, last);
}

void Merge(long* arr, int start, int mid, int last) {
    int k = start;
    int len1 = (mid+1) - start;
    int len2 = last - mid;
    long sub1[len1], sub2[len2];
    
    for (int i=0;i<len1;i++) { sub1[i] = arr[start+i]; }
    for (int i=0;i<len2;i++) { sub2[i] = arr[mid+1+i]; }
    
    int m = 0; int l = 0;    
    while (m < len1 && l < len2) {
        if (sub1[m] > sub2[l]) { arr[k] = sub2[l++]; } 
        else { arr[k] = sub1[m++]; }
        k++;
    }
    
    if (m == len1) {
        for (int x=l;x<len2;x++) { arr[k++] = sub2[x]; }
    } else {
        for (int x=m;x<len1;x++) { arr[k++] = sub1[x]; }
    }
}