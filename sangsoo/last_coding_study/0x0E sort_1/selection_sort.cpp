#include <iostream>
#include <algorithm>

using namespace std;
// 선택정렬 :  arr[i], arr[j]를 비교하면서 바꾸기 한쪽에 큰것부터 쌓기
// 하나(i)를 가지고 여러 개(j)를 비교
int arr[8] = {8, 6, 5, 3, 1, 2, 7, 4};
int main(){
    for(int i = 0; i < 8; i++)
        for(int j = i+1; j < 8; j++)
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
}