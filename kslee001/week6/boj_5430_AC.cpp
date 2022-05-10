#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <regex>

using namespace std;
int main(){
    int t; cin>>t;
    string p;
    stringstream p_ss;
    char func;
    char cur_func;
    
    int direction;
    bool breaker; // loop 멈추게할 flag

    int len;
    string arr; // 수 배열
    stringstream arr_ss; // 숫자 하나씩 받을놈
    regex pattern1(",");  // 배열에서 쓸데 없는 '[', ']', ',' 같은 애들 날리는 regex pattern
    regex pattern2("[\\[\\]]");
    int number;

    deque<int>  deq_nums;
    deque<char> deq_funcs;

    for(int i=0; i<t; ++i){
        direction = 1; // 시작은 정방향
        breaker= false;

        cin >> p; // 수행할 함수를 담을 string p (1~100000)
        cin >> len; // 배열의 길이 len
        cin >> arr; // arr를 string형태로 받아놓기

        string arr_rgx = regex_replace(arr, pattern2, "");
        arr_rgx = regex_replace(arr_rgx, pattern1, " ");  // 여기서 1 2 3 4 형태로 바뀐다!
        arr_ss.clear();
        arr_ss.str(arr_rgx);  // regex로 수정한 놈 받을 stringstream
    
        while(arr_ss>>number){
            deq_nums.push_back(number);
        };

        // cout << " # deq_nums : [";
        // for(int j=0; j<len; ++j){
        //     cout << deq_nums[j];
        //     if( j!= len-1) {cout << ",";}
        // }
        // cout << "]\n";
        
        p_ss.clear();// 함수담은 string p를 p_ss로 쪼개기 
        p_ss.str(p); // 
        while(p_ss>>func){ // p_ss의 각 글자를 char func 에 저장
            deq_funcs.push_back(func); // deq_funcs에 그 function들 저장
        }

        // cout << " # deq_funcs : "<<p<<"\n";;

        while(!deq_funcs.empty()){ // deq_func 비어있을때까지 function 불러오기
            cur_func = deq_funcs.front();  // 현재의 function을 cur_func에 저장
            // cout << "current func : " << cur_func << endl;
            // cout << " --currently emtpy? : " << deq_nums.empty() << endl;
            if(cur_func == 'R'){ // 'R' : direction에 -1 곱하기 : 부호에 따라 front방향 / back 방향 결정
                direction *= -1;   
            }
            else if (cur_func =='D'){  // 'D' :pop 하는 함수 호출 : direction에 따라 방향 다르게 설정
                if(deq_nums.empty()){ // 함수가 비어있는데 D를 호출하는 경우 : error
                    // cout << deq_nums.size() <<"\n";
                    breaker = true; 
                }
                else if(direction == 1){ 
                    deq_nums.pop_front(); // 정방향(direction == 1)  : 앞에서부터 빼기 (-->)
                } 
                else{
                    deq_nums.pop_back(); // 역방향(direction == -1)  : 뒤에서부터 빼기 (<--)
                }
            }
        deq_funcs.pop_front(); // 볼일 다봤으니 pop
        }

        if(breaker == true){
            cout << "error\n";
        }
        else{
            if(direction == 1){ // 정방향인경우
                cout << "[";
                while(!deq_nums.empty()){
                    cout << deq_nums.front(); // deq의 front 출력
                    deq_nums.pop_front();
                    if(!deq_nums.empty()){ // 아직 deq에서 더 뺄게 남아있다면 (empty가 아니라면) ',' 출력
                        cout << ',';
                    }
                }
                cout << "]\n";
            }
            else{                // 역방향인경우
                cout << "[";
                while(!deq_nums.empty()){
                    cout << deq_nums.back(); // deq의 front 출력
                    deq_nums.pop_back();
                    if(!deq_nums.empty()){ // 아직 deq에서 더 뺄게 남아있다면 (empty가 아니라면) ',' 출력
                        cout << ',';
                    }
                }
                cout << "]\n";
            }

        }

    }

}