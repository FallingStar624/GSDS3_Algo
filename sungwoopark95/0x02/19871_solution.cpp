#include <iostream>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X; // cin은 공백 단위로 모두 처리

    int num;
    for (int i=0;i<N;i++) {
        cin >> num; // 따라서 10개의 공백이 있는 경우 반복을 돌면서 다 받아줘야 함
        if (num < X) {
            cout << num << " ";
        }
    }
    cout << endl;
}