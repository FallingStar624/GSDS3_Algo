#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int v;

    cin >> N;

    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> v;

    int answer = 0;
    for(int val : arr) {
        if(val == v) {
            answer++;
        }
    }

    cout << answer;

    return 0;
}