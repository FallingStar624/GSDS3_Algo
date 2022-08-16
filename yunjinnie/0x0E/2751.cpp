// # = N (<=1,000,000), ascending order
// 그 아래 수 차례로 주어짐

#include <iostream>
//#include <vector>
#include <algorithm>
#include <climits>
//#include <bits/stdc++.h>
using namespace std;

int N;
//long long
int seq[1000000]; // int_max
int tmp[1000000];

void merge(int start, int mid, int end){
    //vector<long long> tmp;
    int k = start;

    int i = start;
    int j = mid+1;

    while(i<=mid && j<=end){
        if (seq[i]<=seq[j]){
            //tmp.push_back(seq[i+1]);
            tmp[k] = seq[i++];
        }
        else{
            //tmp.push_back(seq[j+1]);
            tmp[k] = seq[j++];
            //cnt += mid+1-i;
            //k++;
        }
        k++;
    }

    /*while(i<=mid){
        tmp.push_back(seq[i+1]);
    }
    while(j<=end){
        tmp.push_back(seq[j+1]);
    }
    for (int k=start, l=0; k<=end; k++, l++){
        //v[k] = tmp[l];
    }*/
    if (i > mid){
        int idx=j;
        while(idx<=end){
            tmp[k++] = seq[idx]; // not k+1
            idx++;
        }
    }
    else{
        int idx=i;
        while(idx<=mid){
            tmp[k++] = seq[idx];
            idx++;
        }
    }

    int idx = start;
    while(idx<=end){
        seq[idx] = tmp[idx];
        idx++;
    }

}

void mergeHelp(int start, int end){
    int mid = (start + end)/2;
    if (start == end)
        return;
    else{
        mergeHelp(start, mid); // start to mid-1
        mergeHelp(mid+1, end); // mid+1 to end-1
        merge(start, mid, end);
    }
    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i=0; i<N; i++){
        cin >> seq[i];
        //v.push_back(num);
        //scanf("%d", &seq[i]);
    }

    mergeHelp(0, N-1);
    for (int i=0; i<N; i++){
        cout << seq[i] << '\n';
        //printf("%d \n", seq[i]);
    }
    return 0;
}

// quick sort : O(nlogn)~O(n^2)
// merge sort : O(nlogn)
// https://jaimemin.tistory.com/528
// 2750이랑 같은 코드로 내도 통과되는 이유?