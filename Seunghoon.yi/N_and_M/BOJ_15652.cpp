#include <iostream>
#define max 10
using namespace std;

int n, m;
int arr[max] = {0};

void DFS(int start, int cnt){
    if (cnt == m){
        for (int i=0 ; i<m ; i++){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for (int i = start ; i<n ; i++){
        arr[cnt] = i+1;

        DFS(i, cnt+1);
    }
}

int main(){
    cin>>n>>m;
    DFS(0,0);
}