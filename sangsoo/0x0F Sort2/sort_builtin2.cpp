#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)
{
	if (a.first > b.first) // 앞에꺼가 더크게 -> 내림차순
		return true;
	else if (a.first == b.first)
	{
		if (a.second > b.second)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main(){
    vector<pair<int,int>> v;
    v.push_back(make_pair(1, 5));		v.push_back(make_pair(1, 3));
    v.push_back(make_pair(2, 1));		v.push_back(make_pair(1, 6));
    v.push_back(make_pair(5, 5));

    sort(v.begin(), v.end(),comp);
    for (int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}