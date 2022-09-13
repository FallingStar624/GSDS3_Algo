#include <iostream>
#include <string>
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

int N, cnt;
char op[MAX]; // +, - 담을 배열

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    Stack s;
    bool check = true;
    int maximum = 0;
    while (N--) {
        int temp;
        cin >> temp;
        if (maximum < temp) {
            for (int i=maximum+1;i<=temp;i++) {
                op[cnt++] = '+';
                s.push(i);
            }
            maximum = temp;
        }
        
        if (s.top() == temp) {
            s.pop();
            op[cnt++] = '-';
        } else {
            check = false;
            break;
        }
    }
    
    if (!check) { cout << "NO" << "\n"; }
    else {
        for (int i=0;i<cnt;i++) {
            cout << op[i] << "\n";
        }
    }
    
    return 0;
}