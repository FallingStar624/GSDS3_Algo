#include <iostream>

using namespace std;

int n, m;
int arr[10];
int val[10];
bool isused[10];

void func(int k) {
    if(k==m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++) {
        if(!isused[i]) {
            arr[k] = val[i];
            isused[i] = 1;
            func(k+1);
            isused[i] = 0; 
        }
    }

}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> val[i];
    }
    
    // sort
    for(int i=0; i<n; i++) {
        int smallest = i;
        for(int j=i+1; j<n; j++) {
            if(val[smallest] > val[j]) {
                smallest = j;
            }
        }
        int tmp = val[smallest];
        val[smallest] = val[i];
        val[i] = tmp;
    }

    func(0);

    return 0;
}