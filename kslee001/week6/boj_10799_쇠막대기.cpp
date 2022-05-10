#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    cin >> str;
    stack<int> stk;

    int res = 0;
    int unfin = 0;
    char prev;
    for(char c: str){
        if(c == '('){
            unfin ++;
        }

        else{ //     c == ')'
            if(prev == '('){
                unfin --;
                res += unfin;
                // cout << "unfin : " << unfin << "   // res : " << res << endl;
            }
            else{
                res++;
                unfin --;
                // cout << "unfin : " << unfin << "   // res : " << res << endl;

            }
        }
        prev = c;
    }

    cout << res;
}