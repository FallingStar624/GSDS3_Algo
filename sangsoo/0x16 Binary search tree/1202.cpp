//failed , solution (barkingdog)
/*
가장 가격이 높은 보석부터 확인하여 보석을 담을 수 있는 가방 중
최대 무게가 가장 작은 가방을 이용해 담는다.
*/
#include <iostream>
#include <set>
#include <algorithm> // sort
#include <tuple> // tie 
using namespace std;

#define X first
#define Y second

int n, k;
pair <int, int> jewel[300003]; // {가격, 무게}
multiset<int> bag;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> jewel[i].Y >> jewel[i].X;
    sort(jewel, jewel+n);

    for(int i = 0; i < k; i++){
        int c;
        cin >> c;
        bag.insert(c);
    }
    long long ans = 0;
    for(int i = n-1; i >= 0; i--){
        int m, v;
        tie(v, m) = jewel[i];
        auto it = bag.lower_bound(m); // 무게가 m 이상중에 작은것
        if(it == bag.end()) continue;
        ans += v;
        bag.erase(it);
    }
    cout << ans;
}