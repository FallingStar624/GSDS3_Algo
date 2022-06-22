// int -> ll 으로 해결: size*size*3이 최대일 때 int 범위 넘어감...
#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;

void recur(int x, int y, int size, int order) {
//    cout << x << " " << y << " " << size << " " << order << endl;
    if (size==1) {
        cout << order;
        return;
    }
    if (r<=x+size/2-1 && c<=y+size/2-1) { // 1
        recur(x, y, size/2, order-size*size*3/4);
    } else if (r>x+size/2-1 && c<=y+size/2-1) { // 3
        recur(x+size/2, y, size/2, order-size*size/4);
    } else if (r<=x+size/2-1 && c>y+size/2-1) { // 2
        recur(x, y+size/2, size/2, order-size*size*2/4);
    } else {
        recur(x+size/2, y+size/2, size/2, order);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r >> c;
    int max_len = pow(2, n);
    int max_ord = pow(max_len, 2);
    recur(0, 0, max_len, max_ord-1);
    return 0;
gg}

