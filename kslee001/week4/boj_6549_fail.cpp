#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// int arr[INT_MAX][INT_MAX];

int main(){
    int n; 
    for(int x=0; x<2; ++x){
        cin >>n;
        int arr[n] = {};
        vector<int> stack;


        int max_floor = 0;
        for(int i=0; i<n; ++i){
            cin >> arr[i];       // arr : 2 1 4 5 1 3 3
            if(arr[i] >= max_floor){
                max_floor = arr[i];    // 5
            }
        }

        // cout << "max_floor : " << max_floor<<endl;



        int floor_longest[max_floor] = {}; // 층별 최대로 이어진 애들(maximum 값) 찾기
        int cnt = 0;
        int cnt_max = 0;

        for(int j = 0; j<max_floor; ++j){
            cnt = 0;
            cnt_max = 0;
            int current_floor = j+1; // current_floor : 현재 층 수

            for(int i=0; i<n; ++i){            // 모든 직사각형 (arr[i] 에 대해 탐색,  
                if(arr[i] >= current_floor){  // 만약 arr[i] 의 숫자가 현재 층 수 보다 크면
                    cnt ++;   // cnt 추가하기
                }  
                else{         // 작으면 cnt 저장 (넘어가기 전에 max여부 확인하기)
                    if(cnt >= cnt_max){  
                        cnt_max = cnt;

                        cnt = 0;
                    }
                    else{
                        cnt = 0;
                    }
                }
            }    
            if(cnt >= cnt_max){
                cnt_max = cnt;
            }
        floor_longest[j] = cnt_max;    
        }

        int max = 0;
        int res = 0;

        // for(int i=0; i<max_floor; ++i){
        //     cout << "floor_longest[" << i << "] : " << floor_longest[i] << endl;
        // }

        for(int i=0; i<max_floor; ++i){
            res = (i+1) * floor_longest[i];
            if (res >= max){
                max = res;
            }
        }
        cout << max;
    }
    int g;
    cin >> g;

}
