#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    if (a%5 != b%5) return a%5 < b%5;
    return a < b;
}

int main(){
    int a[5] = {1, 4, 5, 2, 7};
    sort(a, a+5);
    int b[5] = {1, 4, 5, 2, 7};
    stable_sort(b, b+5);
    vector<int> c = {1, 4, 5, 2, 7};
    sort(c.begin(), c.end()); // or sort(b.begin(), b.begin()+5);
    vector<int> d = {1, 4, 5, 2, 7};
    stable_sort(d.begin(), d.end()); // or sort(b.begin(), b.begin()+5);

    int e[7] = {1, 2, 3, 4, 5, 6 ,7};
    sort(e, e+7, cmp);


    for(int i = 0; i < 5; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << b[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << c[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << d[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 7; i++){
        cout << e[i] << " ";
    }
    cout << endl;
}