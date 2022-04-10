#include <iostream>
#include <map>
using namespace std;
int main(){

    int n; cin>>n;
    int arr[n];
    int temp;
    for(int i=0; i<n;++i){
        cin >> temp;
        arr[i] = temp;
    }
    map <int, int> m;
    for(int i=0; i<n; ++i){
        m[arr[i]] = 0;
    }
    for(int i=0; i<n; ++i){
        m[arr[i]]++;
    }

    int target; cin >>target;
    cout << m[target];
}