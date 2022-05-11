//failed.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string str;
    cin >> str;
    int tmp = 1;
    int ans = 0;
    for (int i = 0; i <str.length(); i++){
        stack<char> stk;
        if(str[i] == '('){
            tmp *= 2;
            stk.push(str[i]);
        }
        else if(str[i] == '['){
            tmp *= 3;
            stk.push(str[i]);
        }
        else if(str[i] == ')' && str[i-1] == '('){
            ans = tmp;
            tmp /= 2;
            stk.pop();
        }
        else if(str[i] == ')' && stk.top() == '('){
            tmp /= 2;
            stk.pop();
        }
        else if(str[i] == ')' && stk.empty() || str[i] == ')' && stk.top() != '('){
            ans = 0;
            break;
        }
        else if(str[i] == ']' && str[i-1] == '['){
            ans = tmp;
            tmp /= 3;
            stk.pop();
        }
        else if(str[i] == ']' && stk.top() == '['){
            tmp /= 3;
            stk.pop();
        }
        else if(str[i] == ']' && stk.empty() || str[i] == ']' && stk.top() != '['){
            ans = 0;
            break;
        }
    }
    cout << ans;
}
