#include <iostream>
using namespace std;


int n,m;
int arr[10];
bool isused[10];

void func(int k){  // k 번째 수
    if(k==m){      // m개 선택 다한 경우 출력
        for(int i=0; i<m; ++i){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1; i<=n; ++i){ // 1부터 n까지 진행
        if(!isused[i]){      // i번째 수가 아직 선택 안된경우에 대해서만 진행
            arr[k] = i;      // array에 복사
            isused[i] = 1;   // check
            func(k+1);       // k+1로 진행
            isused[i] = 0;   // 모두 끝나면 초기화
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    func(0);
}