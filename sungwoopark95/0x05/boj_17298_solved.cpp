#include <iostream>
#include <string>
#define MAX 1000005
using namespace std;

/*
사실상 BOJ_2493과 같은 문제 -> 다만 방향이 반대방향
전체적인 논리는 똑같이 가져가되, 역순으로 stack에 push & pop하기 때문에
1. input, output array를 각각 설정하고
2. stack에는 가장 큰 수를 하나 push해놓은 다음,
3. input array에 입력을 받고, 뒤에서부터 진행한다.
4-1. s.top()과 비교하게 되는 새로 들어온 값이 s.top()보다 크거나 같다면, 그것보다 큰 값이 s.top()에 올 때까지 pop
4-2. 반복을 멈췄다면, s.top()이 새로 들어온 값보다 크다는 뜻이 되는데,
4-3. 이때 s.top()이 MAX라면, 새로 들어온 값이 적어도 현재까지 input array에서 확인한 값들 가운데 가장 크다는 의미
4-4. 따라서 그런 경우에는 -1을, 아닌 경우에는 s.top()이 새로 들어온 값보다 큰 수 중에 제일 작은 수이므로 s.top()을 output array에 써준다.
4-5. 그런 다음 새로 들어온 값을 stack에 push한다.
5. output array에는 역순으로 쓰여 있으므로 output array의 값을 뒤에서부터 출력한다.
*/

class Stack {
    size_t s_size;
    int arr[MAX];
    public:
    Stack() { s_size = 0; }
    
    void push(int x) { arr[s_size++] = x; }
    int pop() { 
        if (this->isEmpty()) { return -1; }
        return arr[--s_size]; 
    }
    int getSize() { return s_size; }
    bool isEmpty() { return s_size == 0; }
    int top() {
        if (this->isEmpty()) { return -1; }
        return arr[s_size-1];
    }
};

int N;
Stack s;
int input[MAX];
int output[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    s.push(MAX);
    for (int i=0;i<N;i++) {
        cin >> input[i];
    }
    
    for (int i=0;i<N;i++) {
        int val = input[N-i-1];
        while (s.top() <= val) { s.pop(); }
        if (s.top() == MAX) { output[i] = -1; }
        else { output[i] = s.top(); }
        s.push(val);
    }
    
    for (int i=0;i<N;i++) {
        cout << output[N-i-1] << " ";
    }
    cout << "\n";
    
    return 0;
}