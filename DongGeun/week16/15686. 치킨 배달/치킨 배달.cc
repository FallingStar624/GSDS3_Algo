#include <bits/stdc++.h>
using namespace std;

int n,m,cnt;
int board[52][52];
vector<pair<int, int>> chic;
vector<pair<int, int>> house;
int cal_dist(vector<pair<int, int>> v)
{
    int res=0;
    for (int i=0;i<house.size();i++)
    {
        int tmp=50*50*50;
        for (int j=0;j<v.size();j++)
        {
            tmp = min(tmp,abs(house[i].first - v[j].first) + abs(house[i].second - v[j].second));
        }
        res +=tmp;
    }
    return res;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;

    vector<int> dist;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) chic.push_back(make_pair(i, j));
            else if (board[i][j] == 1) house.push_back(make_pair(i, j));
        }
    }
    vector<int> n;

    // 1부터 6까지 생성
    for(int i=0; i<chic.size(); i++){
        n.push_back(i);
    }
    vector<int> ind;
    // k개의 1 추가
    for (int i = 0; i < m; i++) {
        ind.push_back(1);
    }

    for (int i = 0; i < chic.size() - m; i++) {
        ind.push_back(0);
    }
    sort(ind.begin(), ind.end());
    int mn = 50*50*50;
    do {
        vector<pair<int, int>> tmp;
        for (int i = 0; i < ind.size(); i++) {
            if (ind[i]) {
                tmp.push_back(chic[n[i]]);
            }
        }
        mn = min(mn, cal_dist(tmp));
    } while (next_permutation(ind.begin(), ind.end()));
    cout<<mn;
}


