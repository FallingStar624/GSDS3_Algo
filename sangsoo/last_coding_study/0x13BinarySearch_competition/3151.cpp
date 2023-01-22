#include <bits/stdc++.h>
using namespace std;
/*
두개씩 더하고해서 two에 넣고
two + a[k] = 0 을 만족하는 a[k]를 찾는다.
*/

int arr[10002];
vector<int> two;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = 0;
    cin >> N;
    for(int i = 0; i < N-1; i++) cin >> arr[i];
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            two.push_back(arr[i]+arr[j]);
        }
    }
    sort(two.begin(), two.end());
    // two.erase(unique(two.begin(), two.end()), two.end());

    sort(arr, arr + N);
    int cnt = 0;
    cout << "two.size() = " << two.size() << endl;
    for(int i = 0; i < two.size(); i++){
        cout << "two["<< i << "] : " << -two[i] << endl;
        if(binary_search(arr, arr+N, -two[i])){
            cout << " -two[" << i << "] : " << -two[i] << endl;
            cnt++;
        }
    }
    cout << cnt;
}