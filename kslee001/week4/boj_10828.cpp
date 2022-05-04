#include <iostream>
using namespace std;

class Stack{
// member variables
private:
    int stack_size;
    int num_elem;
// member functions
    //constructor
public:
    int* stack_bottom;
    int* stack_top;
    int* cur_ptr;

    Stack(int, int*);
    void push(int);
    void pop();
    void size();
    void empty();
    void top();
};

Stack::Stack(int s, int* arr){
    stack_size = s;
    stack_bottom = arr+s-1;  // 첫번째 : bottom
    stack_top = arr;   // 마지막 : top 
    cur_ptr = stack_bottom; // 처음에는 bottom pointing
    num_elem = 0;
}
void Stack::push(int val){
    if(cur_ptr==stack_top) return;
    *(cur_ptr-1) = val;
    cur_ptr = cur_ptr-1;// 하나 들어오면 포인터도 위로 한칸
    num_elem ++;   // 
}
void Stack::pop(){
    if(cur_ptr == stack_bottom){
        std::cout << -1;
        return; 
    }
    std::cout << *(cur_ptr);
    *(cur_ptr) = 0;
    cur_ptr++; // 하나 빠지면 포인터 밑으로 한칸 
    num_elem --;
}
void Stack::size(){
    std::cout << num_elem;
}
void Stack::empty(){
    if(cur_ptr == stack_bottom){
        std::cout << 1;
    }
    else{
        std::cout << 0;
    }
}
void Stack::top(){
    if(cur_ptr == stack_bottom){
        std::cout << -1;
        return;
    }
    std::cout << *(cur_ptr);
}


int main(){
    int n; cin>>n;
    int arr[n]={};
    Stack stack(n, arr);

    string opt; int v;

    // std::cout << "stack_bottom is at : "<< stack.stack_bottom<<endl;
    // std::cout << "stack_top is at : "<< stack.stack_top<<endl;

    for(int i=0; i<n; ++i){
        cin>>opt;
        // std::cout << "current pointer is at " << stack.cur_ptr<<endl;
        if(opt == "push"){
            cin>>v;
            stack.push(v);
        }
        else if(opt == "pop"){
            stack.pop();
        }
        else if(opt == "size"){
            stack.size();
        }
        else if(opt == "empty"){
            stack.empty();
        }
        else if (opt == "top"){
            stack.top();
        }
        if(opt != "push" && i != n-1){
            std::cout << endl;
        }

    }
    // std::cout << "\ncheck\n";
    // for(int i=0; i<n; ++ i){
    //     std::cout<< arr[i] << endl;
    // }
}