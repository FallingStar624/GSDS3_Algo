#include <iostream>
#include <sstream>
using namespace std;


class Node{
public:
    char val;
    Node* prev;
    Node* next;
    // methods
    Node();
    Node(char);
    Node* cur();
};
Node::Node(){
    val = ' ';
    prev = next = NULL;
}
Node::Node(char v){
    val = v;
    prev = next = NULL;
}
Node* Node::cur(){
    return this;
}
Node* head = new Node();
Node* tail = new Node();
void ins(Node* cur, Node* newnode){
    newnode->prev = cur->prev;
    newnode->next = cur;
    cur->prev->next = newnode;
    cur->prev = newnode;    
    return ;
}

void del(Node* cur){
    if(cur == head->next) return;
    Node* delnode = cur->prev;
    delnode->prev->next = cur;
    cur->prev = delnode->prev;
    delete delnode;
    return ;    
}

int main(){
    head->prev = NULL;
    tail->next = NULL;
    head->next = tail;
    tail->prev = head;

    string str; cin>>str;
    stringstream ss(str);
    int n; cin >> n;

    Node* cur = head; // current node : generated pointing head node
    Node* p_node; // prev node
    Node* n_node; // next node
    Node* newnode; // new node

    cur = tail;
    for(char a: str){
        newnode = new Node(a);
        ins(cur, newnode);
        cur = tail;
    }


    char option; char input;
    for(int i=0; i<n; ++i){
        cin>>option;
        if(option == 'L'){
            if(cur== head->next){
                continue;
            }
            cur = cur->prev;
        }
        else if (option == 'D'){
            if(cur == tail){
                continue;
            }
            cur = cur->next;
        }
        else if (option == 'B'){
            del(cur);
        }
        else if (option == 'P'){
            cin >> input;
            newnode = new Node(input);
            ins(cur, newnode);
        }
    }

    cur = head->next;
    while(cur!= tail){
        if(cur->val != ' ')
            cout << cur->val;
        else break ;
    cur = cur->next;
    }
}
