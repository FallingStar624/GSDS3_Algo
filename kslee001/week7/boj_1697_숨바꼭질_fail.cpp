#include <iostream>
#include <queue>
using namespace std;

int dist[100001];
int arv[100001];
int n,k; 

int f_double(int& n){
    return n*2;
}
int f_plus(int& n){
    return n+1;
}
int f_minus(int& n){
    return n-1;
}



int main(){
    cin >> n >> k;

    queue<int> que;

    int res1;
    int res2;
    int res3;



    que.push(n);
    int next;
    int cur = n;
    while(!que.empty()){
        cur = que.front(); que.pop();
        std::cout << " # current : "<< cur << "\n";
        std::cout << " # current size : " << que.size() << "\n";
        std::cout << " # current dist : " << dist[cur] << "\n";
        for(int d = 0; d<3; ++d){
            if(d == 0){
                next = f_double(cur);
            }
            else if (d == 1){
                next = f_plus(cur);
            }
            else{
                next = f_minus(cur);
            }
            
            if(arv[next] == 1){
                continue;
            }
            else if(next <0 || next >=100001){
                continue;
            }
            else{
                if(next == k){
                    cout << dist[cur]+1;
                    return 0;
                }
                std::cout << " ## " << next << " pushed\n";
                dist[next] = dist[cur] +1;
                que.push(next);
            }
        }
        arv[cur] = 1;
        if(que.front() == k){
            break;
        }
    }

    
}