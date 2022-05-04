#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000000

class Stack {
    private:
    int size;
    int stack[MAXSIZE];
    public:
    Stack() {
        size = 0;
        for (int i=0;i<MAXSIZE;i++) {
            stack[i] = 0;
        }
    }

    void push(int x) {
        stack[size] = x;
        size++;
    }

    int pop() {
        if (size == 0) {
            return -1;
        } else {
            int temp = stack[size-1];
            stack[size-1] = 0;
            size--;
            return temp;
        }
    }

    bool isEmpty() {
        if (size == 0) { return true; }
        else { return false; }
    }

    int getSize() { return size; }

    int getTop() { 
        if (size == 0) { return -1; }
        else { return stack[size-1]; }
    }

    bool inStack(int x) {
        if(isEmpty()) { return false; }
        else {
            int cnt = 0;
            for (int i=0;i<size;i++) {
                if (x == stack[i]) {
                    cnt++;
                }
            }
            if (cnt > 0) { return true; }
            else { return false; }
        }
    }

    void print() {
        for (int i=0;i<size;i++) {
            cout << stack[i] << " ";
        }
        cout << "\n";
    }
};

int seq[MAXSIZE];
char op[MAXSIZE];
int findMax(int arr[], int size);
int min(int x, int y);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    Stack s;
    int n; int x; bool check;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> x;
        seq[i] = x;
    }

    int max_idx = findMax(seq, n);
    for (int i=max_idx+1;i<n;i++) {        
        if (seq[i-1] < seq[i]) {
            cout << "NO" << "\n";
            check = 1;
            break;
        }
    } 
    
    int opcnt = 0;
    if(!check) {
        // 첫 번째 element
        int temp;
        for (int i=0;i<n;i++) {
            if (i == 0) {
                for (int j=0;j<seq[i];j++) {
                    s.push(j+1);
                    // cout << "+" << "\n";
                    op[opcnt] = '+';
                    opcnt++;
                }
                temp = s.pop();
                op[opcnt] = '-';
                opcnt++;
                // cout << "-" << "\n";
            } else {
                int biggest = findMax(seq, i);
                temp = max(seq[biggest], temp);
                if (temp < seq[i]) {
                    int diff = seq[i] - temp;
                    for (int j=0;j<diff;j++) {
                        s.push(temp + (j+1));
                        // cout << "+" << "\n";
                        op[opcnt] = '+';
                        opcnt++;
                    }
                    temp = s.pop();
                    // cout << "-" << endl;
                    op[opcnt] = '-';
                    opcnt++;
                } else { // temp > seq[i]
                    int diff = temp - seq[i];
                    if (diff == 1) {
                        // cout << "-" << "\n";
                        temp = s.pop();
                        op[opcnt] = '-';
                        opcnt++;
                    } else {
                        // s.print();
                        if(s.inStack(seq[i]-1)) {
                            cout << "NO" << "\n";
                            check = 1;
                            break;
                        } else {
                            // cout << "-" << "\n";
                            op[opcnt] = '-';
                            opcnt++;
                            temp = s.pop();
                        }
                    }
                }
            }
        }
    }

    if(!check) {
        for (int k=0;k<opcnt;k++) {
            cout << op[k] << "\n";
        }
    }

    return 0;
}

int findMax(int arr[], int size) {
    // returns the index of the maximum element
    int max = 0;
    for (int i=0;i<size;i++) {
        if (arr[i] > arr[max]) { max = i; }
    }
    return max;
}

int max(int x, int y) {
    return x>y? x : y;
}