#include <iostream>
#include <list>
using namespace std;


int main() {
    int n;
    int k;
    cin >> n >> k;
    list<int> result;
    for (int i=0; i<n; i++) {
        result.push_back(i+1);
    }
    auto cursor = result.begin();
    cout << "<";
    while (n > 1) {
        for (int j=0; j<k-1; j++) {
            if (++cursor == result.end()) cursor = result.begin();
        }
        cout << *cursor << ", ";
        cursor = result.erase(cursor);
        if (cursor == result.end()) cursor = result.begin();
        n--;
    }
    cout << *cursor << ">" << endl;
    return 0;
}
