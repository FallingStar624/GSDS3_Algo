#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    char c;  // 글자 입력받기
    
    bool flag= true; // break용 flag
    stack<char> stk;


    string str;
    while(true){
        flag = true;
        getline(cin, str, '.');
        if(str.length()==1){
            break;
        }
        for(char c : str){
            if(c == '(' || c == ')' || c == '[' || c == ']'){   
                // cout << c << " ";
                switch (c){
                    case ')':
                        if(stk.empty()){
                            flag = false;
                        }
                        else if(stk.top()=='('){
                            stk.pop();
                        }
                        else{
                            flag = false;
                        }
                        break;
                    case ']':
                        if(stk.empty()){
                            flag = false;
                        }
                        else if(stk.top() == '['){
                            stk.pop();
                        }
                        else{
                            flag = false;
                        }
                        break;
                    default:
                        stk.push(c);
                }
            }
        }

        if(flag == false || !stk.empty()){
            cout << "no\n";
            while(!stk.empty()){
                stk.pop();
            }
            flag = true;
        }
        else{
            cout << "yes\n";
            flag = true;      
        }
    }

    return 0;
}
