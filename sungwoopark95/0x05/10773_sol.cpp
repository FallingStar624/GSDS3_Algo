#include <iostream>
#define MAX 1000000
using namespace std;

class Stack {
    size_t s_size;
    int arr[MAX];
    public:
    Stack() { s_size = 0; }
    
    void push(int x) { arr[++s_size] = x; }
    int pop() { 
        if (this->isEmpty()) { return -1; }
        return arr[s_size--]; 
    }
    int getSize() { return s_size; }
    bool isEmpty() { return s_size == 0; }
    int top() {
        if (this->isEmpty()) { return -1; }
        return arr[s_size];
    }
};

int N;
int sum;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Stack s;
    
    cin >> N;
    while (N--) {
        int x;
        cin >> x;
        if (x == 0) { sum -= s.pop(); }
        else {
            s.push(x);
            sum += x;
        }
    }
    
    cout << sum << "\n";
    
    return 0;
}