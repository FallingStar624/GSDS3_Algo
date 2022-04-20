#include <iostream>
#include <list>

using namespace std;

int main() {

    list<int> L = {1, 2};
    list<int>::iterator t = L.begin();
    L.push_front(10); // 10 1 2
    for(auto i : L) cout << i << ' ';
    cout << '\n';

    cout << *t << '\n'; // 1 
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // 10 6 1 2 5
    for(auto i : L) cout << i << ' ';
    cout << '\n';
    t++; 
    t = L.erase(t); // 10 6 1 5
    for(auto i : L) cout << i << ' ';
    cout << '\n';
    cout << *t << '\n'; // 5
    

    

    for(list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << ' ';

    return 0;
}