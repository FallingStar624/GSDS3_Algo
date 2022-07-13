#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define max 13
int answer[max];
bool visited[max] = {0};

void DFS(int start, int cnt, int k, int* data){
    //int arrsize = sizeof(data_)/sizeof(data_[0]);
    if (cnt == 6){
        for (int i=0; i<6; i++){
            cout<<answer[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start ; i<k ; i++){
        if (!visited[i]){
            visited[i] = true;
            answer[cnt] = data[i];
            DFS(i, cnt+1, k, data);
            visited[i] = false;
        }
    }
}

int main(){
    while (true){
        int n;
        cin>>n;
        if (n == 0){
            break;
        }
        int data_[n];
        for (int i = 0; i < n; i++){
            cin >> data_[i];
        }
        sort(data_, data_ + n); 

        DFS(0, 0, n, data_);
        cout<<endl;
    }
}