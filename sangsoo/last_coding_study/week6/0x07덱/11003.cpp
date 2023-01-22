// time over
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
// void printdq(deque<int> dq){
//     cout << "dq: ";
//     for(int i = 0; i < dq.size();i++){
//         cout << dq[i] << ' ';
//     }
//     cout << '\n';
// }
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    deque <int> dq;
    for (int i = 0; i < N; i++){
        int j;
        cin >>j;
        dq.push_back(j);
    }
    
    for(int i = 1; i < N+1; i++){
        deque<int> dqtemp;
        for(int j = i; j < i+L; j++){
            if(j-L+1 >0) {
                dqtemp.push_back(dq[j-L]);
                }
        }
        // printdq(dqtemp);
        cout << *min_element(dqtemp.begin(), dqtemp.end()) << ' ';
    }
}