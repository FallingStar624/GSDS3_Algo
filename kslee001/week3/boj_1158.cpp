#include <iostream>
#include <sstream>
using namespace std;

class Node{
public:
    int val;
    Node* prev;
    Node* next;
    // methods
    Node();
    Node(int);
    Node* cur();
};
Node::Node(){
    val = 0;
    prev = next = NULL;
}
Node::Node(int v){
    val = v;
    prev = next = NULL;
}
Node* head;
Node* tail;
Node* Node::cur(){
    return this;
}
// 헤드 바꾸고 적용
void del(Node* cur){
    Node* delnode;
    if(cur->prev != NULL && cur->next != NULL){
        delnode = cur;
        cur = cur->next;
        delete delnode;
    }
    else{
        delnode = cur;
        cur = cur->next;
        delete delnode;
    }

}

int main(){
    int n, k; cin >>n>>k;
    Node* cur; 
    Node* newnode;

    if(n==1){
        cout << "<" << 1<< ">";
        return 0;
    }

    for(int i=1; i<=n; ++i){
        newnode = new Node(i);
        if (i==1){
            head = newnode;
            cur = head;
        }
        else if(i == n){
            newnode->prev = cur;
            cur->next = newnode;
            cur = cur->next;
            tail = cur;
            tail->next = head;
            head->prev = tail;
        }
        else{
            newnode->prev = cur;
            cur->next = newnode;
            cur = cur->next;
        } 
    }


    std::cout << "<";
    cur = tail;
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<k; ++j){
            cur = cur->next;
        }
        Node* delnode = cur;
        cout << cur->val<<", ";
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        if(cur->prev != NULL)
            cur = cur->prev;
        delete delnode;
    }
    cout << cur->val << ">";

}
