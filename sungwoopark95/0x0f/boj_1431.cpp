#include <iostream>
#include <string>
using namespace std;

struct Serial {
    string item;
    int length;
    int num_sum;
};

int N;
Serial arr[52];

int NumSum(string& x);
void MergeSort(Serial* arr, int len);
void MergeHelp(Serial* arr, int start, int last);
void Merge(Serial* arr, int start, int mid, int last);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        string temp;
        cin >> temp;
        arr[i].item = temp;
        arr[i].length = temp.length();
        arr[i].num_sum = NumSum(temp);
    }
    
    MergeSort(arr, N);
    
    for(int i=0;i<N;i++) {
        cout << arr[i].item << "\n";
    }    
    return 0;
}

int NumSum(string& x) {
    int result = 0;
    for (int i=0;i<x.length();i++) {
        if (x[i] < 'A') { result += x[i]-'0'; }
    }
    return result;
}

void MergeSort(Serial* arr, int len) {
    MergeHelp(arr, 0, len-1);
}

void MergeHelp(Serial* arr, int start, int last) {
    if (start == last) { return; }
    int mid = start + ((last-start)/2);
    MergeHelp(arr, start, mid);
    MergeHelp(arr, mid+1, last);
    Merge(arr, start, mid, last);
}

void Merge(Serial* arr, int start, int mid, int last) {
    int k = start; 
    int len1 = (mid+1) - start; 
    int len2 = last - mid;
    Serial sub1[len1], sub2[len2];
    
    for (int i=0;i<len1;i++) { sub1[i] = arr[start+i]; }
    for (int j=0;j<len2;j++) { sub2[j] = arr[mid+1+j]; }
    
    int m = 0; int l = 0;    
    while (m < len1 && l < len2) {
        if (sub1[m].length > sub2[l].length) { // 길이 비교
            arr[k] = sub2[l++]; 
        } else if (sub1[m].length == sub2[l].length) {
            if (sub1[m].num_sum > sub2[l].num_sum) { // 숫자 합 비교
                arr[k] = sub2[l++];
            } else if (sub1[m].num_sum == sub2[l].num_sum){
                if (sub1[m].item > sub2[l].item) { // 마지막 case - 사전식 나열
                    arr[k] = sub2[l++];
                } else { arr[k] = sub1[m++]; }
            } else { arr[k] = sub1[m++]; }
        }
        else { arr[k] = sub1[m++]; }
        k++;
    }
    
    if (m == len1) {
        for (int x=l;x<len2;x++) { arr[k++] = sub2[x]; }
    } else {
        for (int x=m;x<len1;x++) { arr[k++] = sub1[x]; }
    }
}