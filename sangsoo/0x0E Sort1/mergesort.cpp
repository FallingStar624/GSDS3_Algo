#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& L, int first, int mid, int last){
    int k = first;
    vector<int> sub1(L.begin()+first, L.begin()+mid+1);
    vector<int> sub2(L.begin()+mid+1, L.begin()+last+1);

    int i = 0, j = 0;
    while(i < sub1.size() && j < sub2.size()){
        if(sub1[i] <= sub2[j]){
            L[k] = sub1[i];
            i++;
        }
        else{
            L[k] = sub2[j];
            j++;
        }
        k++;
    }
    while (i < sub1.size()){
        L[k++] = sub1[i++];
    }
    while (j < sub2.size()){
        L[k++] = sub2[j++];
    }
}

void mergeSortHelp(vector<int>& L, int first, int last){
    if(first == last){
        return;
    }
    else{
        int mid = first + (last-first) / 2;
        mergeSortHelp(L, first, mid);
        mergeSortHelp(L, mid+1, last);
        merge(L, first, mid, last);
    }
}

void mergeSort(vector<int>& L){
    mergeSortHelp(L, 0, L.size()-1);
}

int main(){
    vector<int> L = {-4, -102, 1, 3, 0, 2};
    mergeSort(L);
    for (auto num : L){
        cout << num << " ";
    }
    return 0;
}