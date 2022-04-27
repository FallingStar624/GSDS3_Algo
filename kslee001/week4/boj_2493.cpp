#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main(){
    /* input procedure */
    int n; cin>>n;
                    int arr[n]={};           // 1. store hights
                    map<int, int> position;  // 2. store positions
                    map<int, int> res;       // 3. result map for printing
    int max = 0;
    int input;
    for(int i=0; i<n; ++i){
        cin>>input;
        if(max<=input){
            max = input;
        }
        arr[i] = input;
        position[input] = i;
    }
    /*  input ends   : we've got arr[], position(map for address), and max(max hight) */


    // target : current value (arr) 
    stack<int> stk;                 // stack
    int target;

    for(int i=n-1; i>=0; --i){ // arr 뒤에서부터 거꾸로 확인 (target : arr의 원소)
        target = arr[i];
        
        if(stk.empty()==true){ // 스택 비어 있으면 push
            
            stk.push(target);
            // cout << stk.top() << " pushed " << endl;
        }                           
        else if(stk.top()>target){  // 안비어있으면 target과 비교
                                    // 스택 맨 위가 target보다 키 크면 target도 스택에 집어넣음
                                    // (왼쪽 벽에 부딪히지 않음)
            stk.push(target);
            // cout << stk.top() << " pushed " << endl;
            
        }
        else{
            while(stk.empty()!=true&&stk.top()<=target){ // 현재 보고 있는 타워(arr[i])가 스택의 맨 위보다 크다면,  
                                                         // 가능할 때까지 스택에서 제거하고
                                                         // res의 '스택 맨 위에 있던 놈'의 값에 '타워의 위치'를 저장 
                res[stk.top()] = position[target];
                // cout << "current stk.top is : " << stk.top() << " but it will be popped " << endl;
                // cout << "position ["<<stk.top()<<"] is : " << position[stk.top()] << endl;
                stk.pop(); 
            }
            stk.push(target);
            // cout << target << " pushed" << endl;
        }
    }
    while(stk.empty()!= true){
        res[stk.top()] = -1;  // 지워지지 못한 애들(스택에 남아있는 애들)은 모두 res의 포지션을 -1로 설정
        stk.pop();
    }

    int cnt = -1;
    for(int i : arr){
        cnt ++;
        cout << res[i]+1;   // 문제에서 첫번째 기둥의 포지션을 1로 세기 때문에 +1 해줌
                             // 스택에 남아있던애들 (-1 값 갖는 애들)은 0으로 출력될 것임
        if(cnt != n-1){
            cout << " ";
        }
    }
}