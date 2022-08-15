#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
struct Student {
    string name;
    int ko;
    int en;
    int math;
};

Student arr[100001];

bool cmp(Student &a, Student &b) {
    if(a.ko != b.ko) {
        return a.ko > b.ko;
    }

    if(a.en != b.en) {
        return a.en < b.en;
    }

    if(a.math != b.math) {
        return a.math > b.math;
    }

    return a.name < b.name;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].ko >> arr[i].en >> arr[i].math;
    }

    sort(arr, arr + n, cmp);

    for(int i = 0; i < n; i++) {
        cout << arr[i].name << '\n';
    }

    return 0;
}