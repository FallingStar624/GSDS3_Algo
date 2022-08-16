#include <iostream>
#include <algorithm>

using namespace std;
// 삽입정렬 : 숫자를 알맞은 위치에 넣는 정렬

int arr[8] = {8, 6, 5, 3, 1, 2, 7, 4};
int main(){
    int i, j;
    int key;
    for(i = 1; i < 8; i++){
        key = arr[i];
        for(j = i-1;j>=0;j--){ 
            if(arr[j] > key){ // key 의 앞자리를 하나씩 보면서 비교
                arr[j+1] = arr[j]; // 앞자리 값이 key 보다 크면 하나씩 오른쪽으로 이동
            }
            else{
                break; // key보다 작은값이 나오면 break;
            }
        }
        arr[j+1] = key; // 그자리에 key값을 넣는다.
    }
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
}