#include <iostream>
#include <vector>
using namespace std;

int main(){
    unsigned int n; cin >>n;
    unsigned int arr[n];
    unsigned int res = 0;

    vector<unsigned int>stack ={};
    
    unsigned int cur;
    unsigned int temp;

    bool same = false;
    unsigned int same_count = 0;
    unsigned int same_num = 0;

    for(unsigned int i=0; i<n; ++i){
        cin >> cur;
        cout << " cur : " << cur << endl;


        // case 1 : stack이 비어있을 때 -> push
        if(stack.empty()){
            stack.push_back(cur);
            cout << " ## stack is empty, " << cur << " has been pushed\n";
            cout << "   ## " << cur << " has been pushed\n";
            cout << "     ## current front : " << stack.front() <<"\n";
            cout << "     ## current back : " << stack.back() <<"\n";
            cout << "     ## current size : " << stack.size() <<"\n";
            cout << "     ## current res  : " << res          << "\n";
            continue;
        }


        // case 2 : stack에 뭐라도 들어 있을 때, 
           // case 2-1 : cur가 stack의 맨 위(back)보다 크거나 같을 때 -> 교체 
        else if(cur >= stack.back()){ // back 보다 크거나 같을 때
            if(cur == stack.back()){  // 2-1-1. 같을 때 ->그대로 넣음
                same = true;
                same_num = cur;
                cout << "   ## same number appeared :"<<same_num<<" \n";
                cout << "   ## res + "<< stack.size() << "   / res = " << res << endl;
                stack.push_back(cur);
                res = res + stack.size()-1;// + same_count-1;
                cout << "   ## " << cur << " has been pushed\n";
                cout << "     ## current front : " << stack.front() <<"\n";
                cout << "     ## current back : " << stack.back() <<"\n";
                cout << "     ## current size : " << stack.size() <<"\n";
                cout << "     ## current res  : " << res          << "\n";
                continue;
            }
            else{   // 2-1-2. 클 때 -> same false 로 바꾸기
                same = false;
                same_num = 0;
                same_count = 0;
            }

            if(cur < stack.front()){  // front 보다는 작을 때 : front만남기고 flush
                res += stack.size();
                cout << "   ## res + "<< stack.size() << "   / res = " << res << endl;
                temp = stack.front();
                stack.clear();
                cout << "     ## stack has been flushed : last front is " << temp << "\n";
                stack.push_back(temp);
                cout << "   ## " << temp << " has been pushed\n";
                stack.push_back(cur);
                cout << "   ## " << cur << " has been pushed\n";
            }
            else{                     // front 보다 클 때 : new front
                cout << "   ## new front : " << cur << endl;
                res = res + stack.size();
                cout << "   ## res + "<< stack.size() << "   / res = " << res << endl;
                stack.clear();
                stack.push_back(cur);
            }
        }
        else{
            if(same == true){ // 같은것이 있었다면, 가장 최근 것만 남기고 flush
                cout << "   ## different value found : flushing \n"; 
                temp = stack.front();
                stack.clear();
                cout << "   ## " << temp << " has been pushed\n";
                stack.push_back(temp);
                if(temp != same_num){
                    cout << "   ## " << same_num << " has been pushed\n";
                    stack.push_back(same_num);
                } 
                same = false;
            }
            cout << "   ## " << cur << " has been pushed\n";
            stack.push_back(cur);
            res = res + stack.size()-1;
            cout << "   ## res + "<< stack.size()-1 << "   / res = " << res << endl;

        }
        cout << "     ## current front : " << stack.front() <<"\n";
        cout << "     ## current back : " << stack.back() <<"\n";
        cout << "     ## current size : " << stack.size() <<"\n";
        cout << "     ## current res  : " << res          << "\n";
    }    
    cout << res;
}