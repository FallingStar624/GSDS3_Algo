#include <iostream>
using namespace std;

class Node{
private:
    int val;
    Node* prev;
    Node* next;
public:
    //constructor
    Node()      {val = 0; prev = nullptr;  next = nullptr;};
    Node(int v) {val = v; prev = nullptr;  next = nullptr;};

    //getter
    int get_val()      {return val;};
    Node* get_prev()   {return prev;};
    Node* get_next()   {return next;};

    //setter
    void set_val(int v)            {val = v;};
    void set_prev(Node* somenode)  {prev = somenode;};
    void set_next(Node* somenode)  {next = somenode;};
};


class Deque{
private:
    Node* front_sentinel;
    Node* back_sentinel;
    Node* front_curptr;
    Node* back_curptr;

    int cur_size;

public:
    //constructor
    Deque();
    //destructor
    // ~Deque();
    
    // setter
    void push_front(int);
    void push_back(int);
    void pop_front();
    void pop_back();

    // getter
    int size()     {return cur_size;};
    bool empty()   {return cur_size==0;};
    int front()    {if(cur_size ==0) return -1; else return front_curptr->get_val();};
    int back()     {if(cur_size ==0) return -1; else return back_curptr->get_val();};
};

Deque::Deque(){
    // generate new front,back sentinel nodes
    front_sentinel = new Node();
    back_sentinel  = new Node();
    front_curptr = front_sentinel;
    back_curptr  = back_sentinel;
    
    // next/prev setting for front, back nodes 
    front_sentinel->set_next(back_sentinel);
    front_sentinel->set_prev(nullptr);
    back_sentinel->set_prev(front_sentinel);
    back_sentinel->set_next(nullptr);
    
    // current size
    cur_size = 0;
}
// Deque::~Deque(){
//     Node* curnode = front_sentinel->get_next();
//     Node* delnode;
//     while(curnode != back_sentinel){
//         delnode = curnode;
//         curnode = curnode->get_next();
//         delete delnode;
//     }
//     delete front_sentinel;
//     delete back_sentinel;
//     delete this;
// }

void Deque::push_front(int v){
    Node* newnode = new Node(v);
    newnode->set_prev(front_sentinel);
    newnode->set_next(front_curptr);
    front_curptr->set_prev(newnode);
    front_curptr = newnode;
    cur_size ++;
    if(cur_size == 1){
        back_sentinel->set_prev(newnode);
        back_curptr = newnode;
    }
}

void Deque::push_back(int v){
    Node* newnode = new Node(v);
    newnode->set_next(back_sentinel);
    newnode->set_prev(back_curptr);
    back_curptr->set_next(newnode);
    back_curptr = newnode;
    cur_size ++;
    if(cur_size == 1){
        front_sentinel->set_next(newnode);
        front_curptr = newnode;
    }
}

void Deque::pop_front(){
    if(cur_size == 0) {cout << "-1\n"; return;}
    else if (cur_size == 1){
        Node* delnode = front_curptr;

        cout << delnode->get_val() << "\n";
        front_sentinel->set_next(back_sentinel);
        
        back_sentinel->set_prev(front_sentinel);
        front_curptr = front_sentinel;
        back_curptr = back_sentinel;
        delete delnode;
    }
    else{
        Node* delnode   = front_curptr;
        Node* new_front = front_curptr->get_next();

        cout << delnode->get_val() << "\n";

        front_sentinel->set_next(new_front); 
        new_front->set_prev(back_sentinel);
        front_curptr = new_front; 
        delete delnode;
    }
    
    cur_size --;
    return;
}

void Deque::pop_back(){
    if(cur_size == 0) {cout << "-1\n"; return;}
    else if (cur_size == 1){
        Node* delnode = back_curptr;

        cout << delnode->get_val() << "\n";
        front_sentinel->set_next(back_sentinel);
        
        back_sentinel->set_prev(front_sentinel);
        front_curptr = front_sentinel;
        back_curptr = back_sentinel;
        delete delnode;
    }
    else{
        Node* delnode   = back_curptr;
        Node* new_back = back_curptr->get_prev();

        cout << delnode->get_val() << "\n";

        back_sentinel->set_prev(new_back); 
        new_back->set_next(back_sentinel);
        back_curptr = new_back; 
        delete delnode;
    }
    
    cur_size --;
    return;
}



int main(){
    int n; cin >> n;
    string commands[8] ={
        "push_front","push_back",
        "pop_front","pop_back",
        "size","empty",
        "front","back"};
    Deque d;

    string input;
    int input_num;

    for(int i=0; i<n; ++i){
        cin >> input;
        if(input == commands[0]){
            cin >> input_num;
            d.push_front(input_num);
        }
        else if(input == commands[1]){
            cin >> input_num;
            d.push_back(input_num);
        }
        else if (input == commands[2]){
            d.pop_front();
        }
        else if (input == commands[3]){
            d.pop_back();
        }
        else if (input == commands[4]){
            cout <<  d.size() << "\n";
        }
        else if (input == commands[5]){
            cout <<  d.empty() << "\n";
        }
        else if (input == commands[6]){
            cout <<  d.front() << "\n";
        }
        else if (input == commands[7]){
            cout <<  d.back() << "\n";
        }

    }


}

