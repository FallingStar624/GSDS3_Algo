#include <iostream>
using namespace std;

int N;
int arr[20000002];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    
    for (int i=N;i>0;i--) {
        for (int j=0;j<arr[i];j++) {
            cout << i << "\n";
        }
    }
    
    return 0;
}