/*
algorithm
check global max, local max
if local max is greater than global max, assign local max to global max
*/
#include <iostream>
#include <algorithm>
using namespace std;

int in_arr[1002];
int mx_arr[1002];

int find_idx(int x){ // local max를 구하기 위해 x보다는 작은 수들 중에 최댓값의 인덱스를 찾는 함수
    int mx_elm = -1;
    for (int i =0 ; i < x; i++){
        if (in_arr[i] < in_arr[x] && in_arr[i] > mx_elm){
            mx_elm = in_arr[i];
        }
    }
    return mx_elm;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> in_arr[i];
    }
    int mx = 1 ; int local_mx = 0; mx_arr[0] = 1;
    for(int i = 1; i < n; i++){
        if(local_mx > mx){ // local_mx가 mx보다 크면 mx 최신화, local_mx 초기화
            mx = local_mx;
            local_mx = 0;
        }
        if (in_arr[i-1] < in_arr[i]){
            mx++;
            if(local_mx > 0){
                local_mx++;
            }
        }
        if (in_arr[i-1] > in_arr[i]){
            int mx_elm = find_idx(i);
            if (not mx_elm  == -1){
                local_mx = ++mx_arr[mx_elm];
            }
            else {/// mx_elm == -1, 
                local_mx = 1;
            }
        }
        mx_arr[i] = mx;
    }
    cout << mx;
}

