#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

class Node{
public:
    int val;
    Node* prev;
    Node* next;
    //constructor
    Node()      {val = 0; prev = nullptr;  next = nullptr;};
    Node(int v) {val = v; prev = nullptr;  next = nullptr;};
};

class LL{
public:
    Node* curnode;
    int size;
};


int main(){
    int N, M; cin >>N >> M;    
    int arr[M];
    for(int i=0; i<M; ++i){
        cin >> arr[i]; 
    }
    Node* l_nodes[N];
    Node* r_nodes[N];
    for(int i=0; i<N; ++i){
        l_nodes[i] = new Node(i+1);
        r_nodes[i] = new Node(i+1);
    }
    for(int i=0; i<N; ++i){
        if(i==0){
            l_nodes[i]->prev = l_nodes[N-1];
            l_nodes[i]->next = l_nodes[i+1];
            r_nodes[i]->prev = r_nodes[N-1];
            r_nodes[i]->next = r_nodes[i+1];
        }
        else if(i==N-1){
            l_nodes[i]->prev = l_nodes[i-1];
            l_nodes[i]->next = l_nodes[0];
            r_nodes[i]->prev = r_nodes[i-1];
            r_nodes[i]->next = r_nodes[0];
        }
        else{
            l_nodes[i]->prev = l_nodes[i-1];
            l_nodes[i]->next = l_nodes[i+1];
            r_nodes[i]->prev = r_nodes[i-1];
            r_nodes[i]->next = r_nodes[i+1];
        }
    }
    // 여기까지가 circular queue 만드는 과정 (linked list : 서로가 서로의 prev / next 로 연결됨)

    // 시작지점 : 
    Node* l_curnode = l_nodes[0];
    Node* r_curnode = r_nodes[0];



    Node* delnode;
    int count = N;
    int left_rotate;
    int right_rotate;
    int res = 0;
    int temp_res;
    for(int i=0; i<M; ++i){
    // cout << "# current target : " << arr[i] << endl;
    // cout << "current l_curnode : " <<l_curnode->val <<endl;
    // cout << "current r_curnode : " <<r_curnode->val << endl;
        left_rotate  = 0;
        right_rotate = 0;

        //left rotate
        // cout << "left rotate begin \n";
        while(l_curnode->val != arr[i]){
            // cout << " ## current l_curnode : " << l_curnode->val << endl;
            l_curnode = l_curnode->next;
            left_rotate ++;
        }
        // cout << "right rotate begin \n";
        while(r_curnode->val != arr[i]){
            // cout << " ## current r_curnode : " << r_curnode->val << endl;
            r_curnode = r_curnode->prev;
            right_rotate ++;
        }

        temp_res = min(left_rotate, right_rotate);
        res += temp_res;

        count --;
        delnode = l_curnode;
        if(count >=2){
            l_curnode->next->prev = l_curnode->prev;
            l_curnode->prev->next = l_curnode->next;
            r_curnode->prev->next = r_curnode->next;
            r_curnode->next->prev = r_curnode->prev;
            l_curnode = l_curnode->next;
            r_curnode = r_curnode->next;
            delete delnode;
        }
        else if (count == 1){
            l_curnode = l_curnode->next;
            r_curnode = r_curnode->prev;
            l_curnode ->next = nullptr;
            l_curnode-> prev = nullptr;
            delete delnode;
        }

        // cout << "left_rotate  : " << left_rotate << endl;
        // cout << "right_rotate : " << right_rotate << endl;
        // cout << " res         : " << res << endl;
    }
cout << res;



}