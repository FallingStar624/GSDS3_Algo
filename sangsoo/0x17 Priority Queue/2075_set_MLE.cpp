// set으로 시도하였으나 메모리초과
#include <iostream>
#include <set>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int t;
            cin >> t;
            s.insert(t);
        }
    }
    set<int>::iterator it = s.end(); // auto it1
    while(n--){
        it = prev(it);
    }
    cout << *it;
}