#include <iostream>
#include <stack>
using namespace std;

int main(){

    string str; cin >> str;
    stack<char> stk;

    bool flag = true;
    bool closed = false; // recently closed?
    int multiple = 1;
    int addition = 0;
    int res = 0;

    for(char c : str){
        cout << " # current : " << c << endl;

        if(c == '(' || c == '['){
            stk.push(c);

            if(closed == true){     // 최근에 뭔가 닫혀서 multple값이 생겼다면
                addition = addition + multiple;
                multiple = 1;           // addition에 더해주고 multiple 초기화
                closed = false;
                cout << "      case  1 \n";
            }
            else{
                cout << "      case  2 \n";
            }

        }
        else if(stk.empty()){
            cout << "      case  3 (break) \n";
            flag = false;
            break;
        }
        else{
            if(c == ')'){
                if(stk.top() == '('){
                    stk.pop();
                    closed = true;
                    if(!stk.empty()){    // 닫고 보니 stack이 비었다면?  
                                        // -> 지금까지 계산한 것 res에 더하고나서 multiple, addition 초기화
                        cout << "      case  4 \n";
                        res = res + addition + multiple;
                        multiple = 1;
                        addition = 0;
                        closed = false;
                    }
                    else if (stk.empty() && multiple == 1){
                        cout << "      case 4-1 \n";
                        res = res*multiple;
                        multiple = 1;
                        addition = 0;
                        closed = false;
                    }
                    else{    // empty는 아닌데 (뭔가 남아있는데) 계속 닫히고 있는 중이라면
                        cout << "      case  5 \n";
                        multiple = multiple * 2;         // multiple (곱할 값)에 2배 
                    }
                    
                }
                else{
                    cout << "      case  6 (break) \n";
                    flag = false;
                    break;
                }
            }
            else if (c == ']'){
                if(stk.top() == '['){
                    stk.pop();
                    closed = true;
                    if(stk.empty()){
                        cout << "      case  7 \n";
                        res = res + addition + multiple;
                        multiple = 1;
                        addition = 0;
                        closed = false;
                    }
                    else if (stk.empty() && multiple == 1){
                        cout << "      case 7-1 \n";
                        res = res*multiple;
                        multiple = 1;
                        addition = 0;
                        closed = false;
                    }
                    else{
                        cout << "      case  8 \n";
                        multiple = multiple * 3;        // 얘는 mutiple 3배
                    }
                    
                }
                else{
                    cout << "      case  9 (break) \n";
                    flag = false;
                    break;
                }
            }
        }
        cout << " -- multiple : " << multiple << "  // addition : " << addition << "  // res : " << res << endl<<endl;
    }

    if(flag == false){
        cout << 0;
    }
    else{
        cout << res;
    }

}