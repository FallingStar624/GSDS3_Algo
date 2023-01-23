#include <iostream>

using namespace std;

int occur[2000001];
int arr[100001];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int len;
    int x;

    cin >> len;
    
    for(int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    cin >> x;
    int ans = 0;
    for(int i = 0; i < len; i++) {
        
        if(x - arr[i] > 0 && occur[x - arr[i]] > 0) {
            ans++;
        } 
        occur[arr[i]]++;
    }

    cout << ans;


    return 0;
}