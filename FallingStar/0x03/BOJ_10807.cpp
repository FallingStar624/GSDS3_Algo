#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i=0; i<n; i++) cin >> numbers[i];
    int v;
    cin >> v;
    int cnt=0;
    for (int j: numbers) {
        if (j==v) cnt++;
    }
    cout << cnt;
    return 0;
}
