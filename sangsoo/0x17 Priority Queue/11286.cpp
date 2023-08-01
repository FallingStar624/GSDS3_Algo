#include <iostream>
#include <queue>

using namespace std;


struct cmp{ // 배열이나 벡터에서 동작할때랑 반대로 동작..!! 헷갈림 주의!
    bool operator()(int a, int b){
        if (abs(a) != abs(b)) return abs(a) > abs(b); // 이게 배열에서는 내림차순인데 여기서는 오름차순.. 작은게 앞으로옴.. 
        else return a > b;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, cmp> pq;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if (x != 0){
            pq.push(x);
        }
        else{
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else cout << 0 << '\n';
        }
    }
}