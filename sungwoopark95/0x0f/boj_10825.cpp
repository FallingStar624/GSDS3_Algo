#include <iostream>
#include <string>
using namespace std;

int N;
struct Student {
    string name;
    int korean;
    int math;
    int english;
};

Student arr[100002];

void Merge(Student* arr, int start, int mid, int last) {
    int k = start; 
    int len1 = (mid+1) - start; 
    int len2 = last - mid;
    Student sub1[len1], sub2[len2];
    
    for (int i=0;i<len1;i++) { sub1[i] = arr[start+i]; }
    for (int j=0;j<len2;j++) { sub2[j] = arr[mid+1+j]; }
    
    int m = 0; int l = 0;    
    while (m < len1 && l < len2) {
        if (sub1[m].korean > sub2[l].korean) { // 국어점수 비교 - descending
            arr[k] = sub1[m++]; 
        } else if (sub1[m].korean == sub2[l].korean) {
            if (sub1[m].english > sub2[l].english) { // 영어점수 비교 - ascending
                arr[k] = sub2[l++];
            } else if (sub1[m].english == sub2[l].english){
                if (sub1[m].math > sub2[l].math) { // 수학점수 비교 - descending
                    arr[k] = sub1[m++];
                } else if (sub1[m].math == sub2[l].math) {
                    if (sub1[m].name > sub2[l].name) { // 마지막 case - 사전식 나열
                        arr[k] = sub2[l++];
                    } else { arr[k] = sub1[m++]; }
                } else { arr[k] = sub2[l++]; }
            } else { arr[k] = sub1[m++]; }
        }
        else { arr[k] = sub2[l++]; }
        k++;
    }
    
    if (m == len1) {
        for (int x=l;x<len2;x++) { arr[k++] = sub2[x]; }
    } else {
        for (int x=m;x<len1;x++) { arr[k++] = sub1[x]; }
    }
}

void MergeHelp(Student* arr, int start, int last) {
    if (start == last) { return; }
    int mid = start + ((last-start)/2);
    MergeHelp(arr, start, mid);
    MergeHelp(arr, mid+1, last);
    Merge(arr, start, mid, last);
}

void MergeSort(Student* arr, int len) {
    MergeHelp(arr, 0, len-1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i].name >> arr[i].korean >> arr[i].english >> arr[i].math;
    }
    
    MergeSort(arr, N);
    
    for (int i=0;i<N;i++) {
        cout << arr[i].name << "\n";
    }
    
    return 0;
}