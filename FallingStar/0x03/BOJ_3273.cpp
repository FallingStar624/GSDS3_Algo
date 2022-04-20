#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> inputs(n);
    vector<int> index(10000001);
    for (int i; i<n ; i++) cin >> inputs[i];
    for (int j: inputs) index[j]=1;
    int x;
    int cnt = 0;
    cin >> x;
    for (int k: inputs) {
        if(x>k && index[x-k]) cnt++;
    }
    cout << cnt/2;
    return 0;
}
