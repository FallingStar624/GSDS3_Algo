#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    int A, B;
    int arr[N];

    for(int i = 0; i < N; i++) {
        cin >> A >> B;
        arr[i] = A + B;
    } 

    for(int i=0; i <N; i++) {
        cout << arr[i];
        cout << '\n';

    }
    

    


    return 0;
}
