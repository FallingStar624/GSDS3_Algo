#include <stdio.h>

void merge(int L[], int first, int mid, int last){
    int i, j, k;
    int n1 = mid - first + 1;
    int n2 = last - mid;

    // create temp arrays
    int sub1[n1], sub2[n2];

    // copy data to temp arrays sub1[] and sub2[]
    for (i = 0; i < n1; i++)
        sub1[i] = L[first + i];
    for (j = 0; j < n2; j++)
        sub2[j] = L[mid + 1 + j];
    
    // merge the temp arrays back tinto L[first ... last]
    i = 0; // Inital index of first subarray
    j = 0; // Inital index of second subarray
    k = first;
    while ( i < n1 && j < n2){
        if (sub1[i] <= sub2[j]){
            L[k] = sub1[i];
            i++;
        }
        else{
            L[k] = sub2[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of sub1[], if there are any
    while(i < n1){
        L[k] = sub1[i];
        i++;
        k++;
    }
    // Copy the remaining elements of sub2[], if there are any
    while(j < n2){
        L[k] = sub2[j];
        j++;
        k++;
    }
}

void mergeSortHelp(int L[], int first, int last){
    if (first < last){
        // Same as (first + last)/2, but avoids overflow for large first and last
        int mid = first + (last - first)/2;
        // Sort first and second halves
        mergeSortHelp(L, first, mid);
        mergeSortHelp(L, mid+1, last);
        merge(L, first, mid, last);
    }
}

void mergeSort(int L[], int n){
    mergeSortHelp(L, 0, n-1);
}

int main(){
    int L[] = {-4, -102, 1, 3};
    int n = sizeof(L) / sizeof(L[0]);
    mergeSort(L, n);

    for (int i = 0; i < n; i++){
        printf("%d ", L[i]);
    }
    return 0;
}