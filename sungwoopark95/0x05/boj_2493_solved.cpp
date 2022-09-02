#include <iostream>
#define MAXSIZE 500100
#define MAXINT 100000001
using namespace std;

class Stack {
    size_t s_size;
    pair<int, int> arr[MAXSIZE];
    public:
    Stack() { s_size = 0; }
    
    void push(pair<int, int> x) { arr[s_size++] = x; }
    pair<int, int> pop() { 
        if (this->isEmpty()) { return {-1, -1}; }
        return arr[--s_size]; 
    }
    int getSize() { return s_size; }
    bool isEmpty() { return s_size == 0; }
    pair<int, int> top() {
        if (this->isEmpty()) { return {-1, -1}; }
        return arr[s_size-1];
    }
};

int N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Stack s;

    cin >> N;
    s.push({MAXINT, 0}); // infinite loop 피하기 위함
    for (int i=1;i<=N;i++) {
        int height;
        cin >> height;
        while (s.top().first <= height) {
            // 새로 들어온 height이 s.top()의 값보다 크다면, stack에 들어있는 height보다 작은 값이 나올때의 index가 필요함
            // 따라서 계속해서 stack을 비워줌
            s.pop();
        }
        // 반복을 빠져나왔다면, s.top()의 height는 새로 들어온 height보다 클 것임 -> 그때의 index 출력
        cout << s.top().second << " ";
        // 새로 들어온 height이 s.top()의 값보다 작다면 반복을 바로 빠져나올 것이고, 따라서 s.top()의 index가 그대로 출력
        // 따라서 이전에 들어온 height의 index는 항상 저장되어 있어야 함.
        s.push({height, i});
    }
    
    return 0;
}