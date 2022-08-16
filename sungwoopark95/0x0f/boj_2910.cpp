#include <iostream>
using namespace std;

int N, C;
struct Number {
    int count;
    int order;
    int item;
};
Number order[1003];

int In(Number* arr, int num, int len) {
    for (int i=0;i<len;i++) {
        if (arr[i].item == num) { return i; }
    }
    return 0;
}

void Merge(Number* arr, int start, int mid, int last) {
    int k = start;
    int len1 = (mid+1) - start;
    int len2 = last - mid;
    Number sub1[len1], sub2[len2];
    
    for (int i=0;i<len1;i++) { sub1[i] = arr[start+i]; }
    for (int i=0;i<len2;i++) { sub2[i] = arr[mid+1+i]; }
    
    int l = 0, m = 0;
    while (l < len1 && m < len2) {
        if (sub1[l].count > sub2[m].count) {
            arr[k] = sub1[l++];
        } else if (sub1[l].count == sub2[m].count) {
           if (sub1[l].order > sub2[m].order) {
               arr[k] = sub2[m++];
           } else { arr[k] = sub1[l++]; }
        } else { arr[k] = sub2[m++]; }
        k++;
    }
    
    if (l == len1) {
        for (int x=m;x<len2;x++) { arr[k++] = sub2[x]; }
    } else {
        for (int x=l;x<len1;x++) { arr[k++] = sub1[x]; }
    }
}

void MergeHelp(Number* arr, int start, int last) {
    if (start == last) { return; }
    int mid = start + ((last-start)/2);
    MergeHelp(arr, start, mid);
    MergeHelp(arr, mid+1, last);
    Merge(arr, start, mid, last);
}

void MergeSort(Number* arr, int len) {
    MergeHelp(arr, 1, len-1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> C;
    int len = 1;
    for (int i=0;i<N;i++) {
        int temp;
        cin >> temp;
        int is_in = In(order, temp, len);
        if (!is_in) { // 없다면
            order[len].item = temp;
            order[len].order = len;
            order[len].count = 1;
            len++;
        } else { // 이미 밌다면
            order[is_in].count++;
        }
    }
    
    MergeSort(order, len);
    
    for (int i=1;i<len;i++) {
        int cnt = order[i].count;
        for (int j=0;j<cnt;j++) {
            cout << order[i].item << " ";
        }
    }
    cout << "\n";
    return 0;
}