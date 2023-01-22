#include <iostream>
using namespace std;
// merge sort failed

int sorted[1000002];

void merge(int *data, int start, int mid, int end){
    int i = start;
    int j = mid + 1;
    int k = start;

    while(i <= mid && j <= end){
        if(data[i] <= data[j]){
            sorted[k] = data[i];
            i++;
        }
        else{ // data[i] > data[j]
            sorted[k] = data[j];
            j++;
        }
        k++;
    }
    if(i > mid){ // i를 다 채워주었으니 j가 남음
        for(int t = j; t <= end; t++){
            sorted[k] = data[t];
            k++;
        }
    }
    else{ // j > end j를 다 채워주었으니 i가 남음
        for(int t = i; t <= mid; t++){
            sorted[k] = data[t];
            k++;
        }
    }
    for (int t = start; t<= end; t++){
        data[t] = sorted[t];
    }
}

void merge_sort(int *data, int start, int end){
    if(start < end){
        int mid = (start+end)/2;
        merge_sort(data, start, mid); // 좌측정렬
        merge_sort(data, mid+1, end); // 우측정렬
        merge(data, start, mid, end);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int data[N];
    for(int i=0; i<N; i++){
        cin >> data[i];
    }
    merge_sort(data, 0, N);
    for(int i = 0; i <N; i++){
        cout << data[i] << '\n';
    }
}