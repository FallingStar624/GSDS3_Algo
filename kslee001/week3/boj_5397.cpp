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


void ins(Node* cur, Node* newnode){
    newnode->prev = cur->prev;
    newnode->next = cur;
    cur->prev->next = newnode;
    cur->prev = newnode;    
    return ;
}
Node* head;
Node* tail;
void del(Node* cur){
    if(cur == head->next) return;
    Node* delnode = cur->prev;
    delnode->prev->next = cur;
    cur->prev = delnode->prev;
    delete delnode;
    return ;    
}

int main(){
    int n; cin>>n;
    Node* cur;
    Node* newnode;
    char temp;
    string str;
    stringstream ss;

    for(int i=0; i<n; ++i){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        ss.clear();
        cin>>str;
        ss.str(str);
        cur = tail;
        while(ss>>temp){
            if(temp =='<'){
                if(cur!=head->next){
                    cur = cur->prev;
                }
            }
            else if (temp == '>'){
                if(cur != tail){
                    cur = cur->next;
                }
            }
            else if (temp == '-'){
                del(cur);
            }
            else{
                newnode = new Node(temp);
                ins(cur, newnode);
            }    
        }  

        cur = head->next;
        while(cur!= NULL){
            cout << cur->val;
            cur = cur->next;
        }

    }
}