#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, L; cin >> n>>L;

    deque<pair<int, int>> deq; // idx, value

    int range;
    pair<int, int> cur;
    for(int idx=0; idx<n; idx++){
        cur.first = idx;
        cin >> cur.second;
        range = idx-L+1;


        // cout << " # current : " << cur.second << endl;

        // 1. deq에서 range 벗어난애들 제거
        while( deq.size()  &&  deq.front().first < range ){
            deq.pop_front();
        }
        // 2. input과 비교
        // 1) front가 크거나 같은 경우 -> 새로운 front
        if(deq.front().second >= cur.second){
            // cout << " case 3 - 1\n"; 
            while( deq.size()  &&  deq.front().second >= cur.second ){
                deq.pop_front();
            }
        }
        // 2) back이 크거나 같은 경우 -> 
        else{
            // cout << " case 3 - 2\n";
            while( deq.size()  &&  deq.back().second >= cur.second ){
                deq.pop_back();   
            }
        }
        deq.push_back(cur);
 
        cout << deq.front().second << " ";
    }

}