// failed  왜 출력이 안될까..
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// void printstk(stack<char> stk){
//     for(int i = 0; i < stk.size();i++){
//         cout << stk.top();
//         stk.pop();
//     } 
// }
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    while(1){  
        string str;
    	stack<char> stk;
        getline(cin, str);
        for (int i =0; i<str.length(); i++){
            if(str[i]== '(' || str[i]== '{' ||str[i]== '[' ) {stk.push(str[i]);}
            else if(str[i]== ')'){
                if (stk.top() == '('){stk.pop();}
            }
            else if(str[i]== '}'){
                if (stk.top() == '{'){stk.pop();}
            }
            else if(str[i]== ']'){
                if (stk.top() == '['){stk.pop();}
            }
            else if(str[i]== '.'){
                if(stk.empty()) {cout << "yes" << '\n'; break;}
                else {cout << "no"<< '\n'; break;}
            }
        }

        if (str == ".") break;

    }
    return 0;
}