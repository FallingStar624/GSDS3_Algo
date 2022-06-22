#include <iostream>
using namespace std;

string start = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
string question =  "\"재귀함수가 뭔가요?\"\n";
string ans1 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
string ans2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
string ans3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
string ans4 = "라고 답변하였지.\n";
string ans5 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
// string start = "start\n";
// string question = "\"question?\"\n";
// string ans1 = "\"answer1\n";
// string ans2 = "answer2\n";
// string ans3 = "answer3\"\n";
// string ans4 = "answer4\n";

void func(int n, int idx){
    // base case
    if(n==0) {
        for(int i=0; i<idx; ++i){cout << "____";}
        cout << question;
        for(int i=0; i<idx; ++i){cout << "____";}
        cout << ans5;
        for(int i=0; i<idx; ++i){cout << "____";}
        cout << ans4;
        return;
    }
    
    // recursive case
    for(int i=0; i<idx; ++i){cout <<"____";}
    cout << question;
    for(int i=0; i<idx; ++i){cout <<"____";}
    cout << ans1;
    for(int i=0; i<idx; ++i){cout <<"____";} 
    cout << ans2;
    for(int i=0; i<idx; ++i){cout <<"____";} 
    cout << ans3;
    n--;
    idx++;
    func(n, idx);
    for(int i=0; i<idx-1; ++i){cout<<"____";}
    cout << ans4;
};



int main(){
    int n; cin >>n;    
    cout << start;
    int idx = 0;
    func(n, idx);
}