#include <iostream>
/*
algorithm
find increasing progressions and sum

before unpdating cumul[i], you must chech if it is maximum
*/

using namespace std;

int in_arr[1002];
int cumul[1002];
int mx; // 구하는 최종값
int mx2; // for edge case(직전것을 더하는것보다 중간값을 더하는것이 유리할때가 있음) 
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> in_arr[i];
    }

    cumul[0] = in_arr[0];
    mx = cumul[0];
    for (int i = 1 ; i < n; i++){
        if(in_arr[i] > in_arr[i-1]){ // 만약 i번째 인풋값이 전꺼보다 더 크다면
            mx2 = in_arr[i-1]; // mx2를 in_arr[i-1]로 초기화한다.
            for(int j = i-1 ; j >= 0; j--){  // i-1부터 반대로 수열을 확인한다.
                if(mx2 < in_arr[j] && in_arr[j] < in_arr[i]){ // mx2를 찾는다
                    mx2 = in_arr[j];
                    if(cumul[i] < cumul[j] + in_arr[i]){ // cumul[i]를 업뎃 하기전에 항상 확인
                        cumul[i] = cumul[j] + in_arr[i];
                    }
                }
                else{

                    if(cumul[i] < cumul[i-1] + in_arr[i]){ // cumul[i]를 업뎃 하기전에 항상 확인
                        cumul[i] = cumul[i-1] + in_arr[i];
                    }
                }
            }
        }
        else{ // in_arr[i] <= in_arr[i-1]
            for (int j = i-1; j >= 0; j--){
                if(cumul[i] < in_arr[i]){ // cumul[i]를 업뎃 하기전에 항상 확인
                    cumul[i] = in_arr[i]; // cumul[i]를 일단 in_arr[i]로 초기화
                }
                if(in_arr[j] < in_arr[i]){ // in_arr[j]가 in_arr[i] 보다 작으면, 
                    if(cumul[i] < cumul[j]+in_arr[i]){ // cumul[i]를 업뎃 하기전에 항상 확인
                        cumul[i] = cumul[j] + in_arr[i]; // 그 작은 값은 증가수열의 일부이므로 더한다.
                    }
                }
            }
        }
        if(mx < cumul[i]){
            mx = cumul[i];
        }
    }

    cout << mx;
}