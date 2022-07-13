#include <iostream>
using namespace std;

int N;
int cnt_answer = 0;

int visited[15];

bool check(int row){
    for (int i = 0; i < row; i++){
        if (visited[row] == visited[i] || row - i == abs(visited[row] - visited[i])){
            return 0;
        }
    }
    return 1;
}

void solveNQ(int row){
    if (row==N){
        cnt_answer++;            // if all queens are placed, return true
        return;
    }
    for(int i = 0 ; i<N ; i++){
        visited[row] = i;       // queens must be placed in different rows
        if (check(row)){
            solveNQ(row+1);
        }
    }
}

int main(){
    cin >> N;
    solveNQ(0);
    cout<<cnt_answer<<endl;
}