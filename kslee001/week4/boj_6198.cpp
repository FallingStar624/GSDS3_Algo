#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    long long int cnt = 0;
    int arr[n];
    vector<int> stack;


    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }

    for(int i=0; i<n; ++i){
        while(!stack.empty() && stack.back()<= arr[i]){
            stack.pop_back();
        }
        stack.push_back(arr[i]);
        cnt += stack.size()-1;
    }

    cout << cnt;
    



}