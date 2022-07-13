#include <iostream>
#define max 9
using namespace std;

int n, m;
int arr[max] = {0};
bool visited[max] = {0};

void DFS(int start, int cnt){
    if (cnt == m){
        for (int i=0; i<m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start ; i<=n ; i++){
        if (!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            DFS(i+1, cnt+1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n>>m;

    DFS(1,0);
}