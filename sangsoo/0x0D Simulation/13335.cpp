// 틀렸는데.... 도저히 모르겠음.
// 일단 기본적인 테스트 케이스는 모두 통과

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, w, L, idx, sum, cnt;
    cin >> n >> w >> L;
    vector <int> v;
    deque<int> dq, dq2, dq3;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        dq.push_back(tmp);
    }
    idx = 0; sum = 0; cnt = 1;
    dq2.push_back(idx); idx += 1;// 다리에 어떤 트럭이 올라와 있는지 저장 // idx는 다리에 들어갈 트럭의 index를 가리킴
    sum += dq.front(); dq.pop_front();
    int numzero = 0;
    while(1){
        // 맨 앞차의 무게 설정
        int front_truck = 0; 
        if (dq2.front() == -1) front_truck = 0; // dummy 변수이면, 0;
        else front_truck = v[dq2.front()]; 
        // 각 경우 마다 확인
        if ((sum + dq.front() <= L) && (dq2.size() < w) && (idx < n)){ // 최대하중도 안넘고, 다리에 트럭이 다 안찼을때
            sum += dq.front(); dq.pop_front();
            dq2.push_back(idx); idx += 1;
            cnt += 1;
        }
        else if ((sum + dq.front() > L) && (dq2.size() < w) && (idx < n)){ // 최대하중은 넘어서 다음 트럭이 들어 올 수 없고, 다리에 트럭이 다 안찼을때안찼을때
            dq2.push_back(-1); // dummy value 를 넣어준다.
            numzero += 1;
            cnt += 1;
        }
        else if ((sum + dq.front() - front_truck <= L) && (dq2.size() == w) && (idx < n)){ // 다리에 트럭이 다 찼는데, 앞에 트럭이 나가고 다음 트럭이 들어올 수 있을 때
            sum = sum + dq.front() - front_truck; dq.pop_front();
            if (dq2.front() == -1) numzero -= 1;
            dq2.push_back(idx); idx += 1; dq2.pop_front();
            cnt += 1;
        }
        else if ((sum + dq.front() - front_truck) > L && (dq2.size() == w) && (idx < n)){ // 다리에 트럭이 다 찼는데, 앞에 트럭이 나가고 다음 트럭은 들어올 수 없을 때
            if (dq2.front() == -1) numzero -= 1;
            dq2.pop_front(); dq2.push_back(-1); // 앞 차를 내보내고, dummy value 를 넣어준다
            numzero += 1;            
            cnt += 1; sum -= front_truck;
        }
        else if ((idx == n)){ // 마지막 차가 입장 할 차례가 되면... 길이 만큼 시간을 더해준다.
            if ((numzero == 0) || (numzero == 1)) cnt += w;
            else if (dq.front() == 0) cnt += w;
            else cnt += (w-numzero);
            break;
        }

    }
    cout << cnt;
}