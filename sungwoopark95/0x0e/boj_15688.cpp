#include <iostream>
#define START 1000000
using namespace std;

int N;
int arr[2000002];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        int temp;
        cin >> temp;
        arr[temp+START]++;
    }
    
    for (int i=0;i<=2000000;i++) {
        for (int j=0;j<arr[i];j++) {
            cout << i-START << "\n";
        }
    }
    
    return 0;
}