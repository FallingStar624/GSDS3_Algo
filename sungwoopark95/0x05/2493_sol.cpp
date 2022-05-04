#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 500000

int towers[MAXSIZE];
int findMax(int arr[], int size);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N; int tower; 
    int size = 0;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> tower;
        towers[i] = tower;
        size++;
    }

    int seqmax = findMax(towers, size);
    int big = 0;
    for (int i=0;i<size;i++) {
        if (i == 0 || i == seqmax) { cout << 0 << " "; }
        else {
            if (towers[i-1] > towers[i]) {
                big = i;
                cout << big << " ";
            } else {
                if (towers[seqmax] > towers[i]) {
                    if (seqmax < i) {
                        big = seqmax+1;
                        cout << big << " ";
                    } else {
                        cout << big << " ";
                    }
                } else {
                    cout << big << " ";
                }
            }
        }
    }
    cout << "\n";
    
    return 0;
}

int findMax(int arr[], int size) {
    int max = 0;
    for (int i=0;i<size;i++) {
        if (arr[max] < arr[i]) {
            max = i;
        }
    }
    return max;
}