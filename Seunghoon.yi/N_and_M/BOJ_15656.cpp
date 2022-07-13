#include <iostream>
#include <algorithm>
#define max 9
using namespace std;

int n, m;
int data_[max], answer[max];
int arr[max] = {0};
bool visited[max] = {0};

void DFS(int start, int cnt){
    if (cnt == m){
        for (int i=0; i<m; i++){
            cout<<answer[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start ; i<n ; i++){
        if (!visited[i]){
            visited[i] = true;
            answer[cnt] = data_[i];
            DFS(i, cnt+1);
        }
        visited[i] = false;
    }
}

int main(){
    cin >> n>>m;
    for (int i = 0; i < n; i++)
	{
		cin >> data_[i];
	}
	sort(data_, data_ + n); 

    DFS(0, 0);
}