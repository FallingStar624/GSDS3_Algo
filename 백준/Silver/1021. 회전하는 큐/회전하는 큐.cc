#include <bits/stdc++.h>
using namespace std;
int N,K,num,cnt;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> N>>K;
    deque<int> Q;
    for (int i=0;i<N;i++) {
        Q.push_back(i+1);
    }
    while(K-->0)
    {
        cin >> num;
        int index=0;
        for (auto i = Q.begin(); i != Q.end(); i++) {
            index++;
            if (*i==num)
            {
                break;
            }
        }
        //cout<<index<<": index \n";
        if (index-1<=Q.size()-index+1)
        {
            while (num!=Q.front())
            {
                Q.push_back(Q.front());
                //cout<<Q.front()<<" front->back\n";
                Q.pop_front();
                cnt++;
            }
        }
        else
        {
            while (num!=Q.front())
            {
                Q.push_front(Q.back());
                //cout<<Q.back()<<" back->front\n";
                Q.pop_back();
                cnt++;
            }
        }
        Q.pop_front();
    }
    cout<<cnt;

}