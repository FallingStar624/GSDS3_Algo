#include <iostream>
using namespace std;

class linkedlist{
    public:
    string val;
    linkedlist* next;
    linkedlist* head;
    linkedlist(string str){
        val = str;
        next = NULL;
    }
    linkedlist(){
        val = "";
        next = NULL;
    }
};


int main(){
    int n; cin>>n;

    int arr[n]= {};
    int temp;
    for(int i=0; i<n; ++i){
        cin>>temp;
        arr[i] = temp;
    }   // 여기까지 데이터 집어넣기


    bool flag = true;
    int stack[n]={};
    int* ptr = stack-1;
    int* b = stack;
    int* t = stack+n-1; // stack [ bottom-------top ]
    //  스택만들기                   0           n-1
    
    // 출력용 linkedlist
    linkedlist* head = new linkedlist();
    linkedlist* cur = head;
    linkedlist* newnode;

    int target;
    int cnt=1;
    for(int i=0; i<n; ++i){
        target = arr[i];
        // cout << " ###### target : "<< target << " / i : "<< i << endl;
        // cout << "[init] current target is : "<< target << endl;
        // cout << "[init] current cnt is : " << cnt << endl;
        // cout << "[init] current pointer is at : " << ptr-b << endl;
        // cout << "[init] current pointer value is : " << *ptr << endl;

        while(cnt<=target){   // 지금 보고 있는 array의 숫자가 아직 안나왔다면
                              // 그만큼 stack 쌓아올림(포인터 이동하고 stack array에 값 넣기)
            if(cnt!=target+1) {ptr++;}            
            *ptr = cnt;
            newnode = new linkedlist("+");
            cur-> next = newnode;
            cur = cur->next;
            cnt++;
                // cout << " ## [push] current target is : "<< target << endl;
                // cout << " ## [push] current cnt is : " << cnt << endl;
                // cout << " ## [push] current pointer is at : " << ptr-b << endl;
                // cout << " ## [push] current pointer value is : " << *ptr << endl;
        }

        
        // cout << "( check )\n";
        // for(int i=0; i<n; ++i){
        //     cout << stack[i] << " ";
        // }
        // cout << "\n";


        if(*ptr != target){   // stack 쌓아올려진 상태라면 
                              // 다음번에 빠질 애가 target이랑 같은지 확인
                              // 만약 다르다면 잘못된거니까 NO출력
                              // 같다면 stack에서 제거(제거하고 포인터 내리기)
            flag = false; break;
        }
        else{
            newnode = new linkedlist("-");
            cur->next = newnode;
            cur = cur->next;
            *ptr = 0;
            if(ptr!=b) {ptr--;}
        }
        // cout << " ## [pop] current target is : "<< target << endl;
        // cout << " ## [pop] current cnt is : " << cnt << endl;
        // cout << " ## [pop] current pointer is at : " << ptr-b << endl;
        // cout << " ## [pop] current pointer value is : " << *ptr << endl;
    }

    if(flag == false){
        cout << "NO"; return 0;
    }
    else{
        cur = head->next;
        while(cur != NULL){
            cout << cur->val << "\n";
            cur = cur->next;
            
        }
    }





}