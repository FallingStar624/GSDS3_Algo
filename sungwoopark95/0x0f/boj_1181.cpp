#include <iostream>
#include <string>
using namespace std;

int N;
string arr[20002];

bool In(string* arr, string& x, int len) {
    for (int i=0;i<len;i++) {
        if (arr[i] == x) { return true; }
    }
    return false;
}

void Merge(string* arr, int start, int mid, int last) {
    int k = start;
    int len1 = (mid+1) - start;
    int len2 = last - mid;
    string sub1[len1], sub2[len2];
    
    for (int i=0;i<len1;i++) { sub1[i] = arr[start+i]; }
    for (int i=0;i<len2;i++) { sub2[i] = arr[mid+1+i]; }
    
    int l = 0, m = 0;
    while (l < len1 && m < len2) {
        if (sub1[l].length() > sub2[m].length()) { // 길이 비교
            arr[k] = sub2[m++]; 
        } else if (sub1[l].length() == sub2[m].length()) {
            if (sub1[l] > sub2[m]) {
                arr[k] = sub2[m++];
            } else { arr[k] = sub1[l++]; }
        }
        else { arr[k] = sub1[l++]; }
        k++;
    }
    
    if (l == len1) {
        for (int x=m;x<len2;x++) { arr[k++] = sub2[x]; }
    } else {
        for (int x=l;x<len1;x++) { arr[k++] = sub1[x]; }
    }
}

void MergeHelp(string* arr, int start, int last) {
    if (start == last) { return; }
    int mid = start + ((last-start)/2);
    MergeHelp(arr, start, mid);
    MergeHelp(arr, mid+1, last);
    Merge(arr, start, mid, last);
}

void MergeSort(string* arr, int len) {
    MergeHelp(arr, 0, len-1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    int len = 0;
    for (int i=0;i<N;i++) {
        string temp;
        cin >> temp;
        if (!In(arr, temp, len)) {
            arr[len++] = temp;
        }
    }
    
    MergeSort(arr, len);
    
    for (int i=0;i<len;i++) {
        cout << arr[i] << "\n";
    }
    
    return 0;
}