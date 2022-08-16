// sort : age ascending, if same age -> first person, first out
// # = N (<=100,000), 1<=age<=200, name(string)<100

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
struct Person {
        int age;
        int index;
        string name;
};

// main 외부에서 선언되어야 함
bool comp(const Person &a, const Person &b){ // 연산자 오버로딩
    if (a.age<b.age) return true;
    else if (a.age == b.age) return a.index < b.index;
    else return false;
}

int main(void) {
    cin >> n;
    vector <Person> v(n);

    for (int i=0; i<n; i++){
        cin>> v[i].age>> v[i].name;
        v[i].index = i;
    }

    sort(v.begin(), v.end(), comp);

    for (int i=0; i<n; i++){
        cout << v[i].age << ' '<< v[i].name << '\n';
    }
    return 0;
}

// stable_sort
// https://ldgeao99.tistory.com/341