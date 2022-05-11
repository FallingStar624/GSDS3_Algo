//failed

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string str;
    cin >> str;
    int tmp = 0;
    int ans = 0;
    stack<char> stk;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '('){
            stk.push(str[i]);
            
        }
        else if (str[i] == ')'){
            if (i >0 && str[i-1] == '('){
                ans += stk.size();
                stk.pop();
            }
            else if (i >0 && stk.top() == '('){
                ans += 1;
                stk.pop();
            }
        }
    }
    cout << ans;

}