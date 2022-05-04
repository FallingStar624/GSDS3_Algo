#include <iostream>
using namespace std;

class Queue;
class Node{
    friend class Queue;
public:
    int val;
    Node* next;
    Node* prev;
    Node();
    Node(int);
};

Node::Node(){
    val = 0;
    next = nullptr;
    prev = nullptr;
}
Node::Node(int v){
    val = v;
    next = nullptr;
    prev = nullptr;
}


class Queue{
private:
    Node* head;
    Node* tail;
    int s;
public:
    Queue();
    ~Queue();
    void push(int);
    int pop();
    int size();
    int empty();
    int front();
    int back();
};
Queue::Queue(){
    head = new Node(0);
    tail = new Node(0);
    head->next = tail;
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
    s = 0;
}
Queue::~Queue(){
    Node* curnode = head->next;
    Node* delnode;
    while(curnode!=nullptr){
        delnode = curnode;
        curnode = curnode->next;
        delete delnode;
    }
}
void Queue::push(int v){
    Node* newnode = new Node(v);
    if(s == 0){
        head->next = newnode;
        tail->prev = newnode;
        newnode->next = tail;
        newnode->prev = head;
    }
    else{
        newnode->next = tail;
        newnode->prev = tail->prev;
        tail->prev->next = newnode;
        tail->prev = newnode;
    }
    s++;
    return;
}

int Queue::pop(){
    if(s == 0) return -1;
    else{
        Node* curnode = head->next;
        int ret = curnode->val;
        head->next = curnode->next;
        curnode->next->prev = head;
        delete curnode;
        s--;
        return ret;
    }
}

int Queue::size(){
    return s;
}

int Queue::empty(){
    int ret;
    if(s==0) ret = 1;
    else ret = 0;
    return ret;
}

int Queue::front(){
    if(s == 0) return -1;
    return head->next->val;
}

int Queue::back(){
    if(s == 0) return -1;
    return tail->prev->val;
}


int main(){
    int n; cin>>n;
    Queue q;
    string option; int item;
    for(int i=0; i<n; ++i){
        cin >> option;
        if(option=="push"){
            cin>> item;
            q.push(item);
            continue;
        }
        else if(option == "pop"){
            cout << q.pop();
        }
        else if (option == "front"){
            cout << q.front();
        }
        else if (option == "back"){
            cout << q.back();
        }
        else if (option == "size"){
            cout << q.size();
        }
        else if (option == "empty"){
            cout << q.empty();
        }
        cout << endl;
    }

}