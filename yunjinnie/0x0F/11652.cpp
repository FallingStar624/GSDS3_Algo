// 1st row: # of cards N (1<=, =<100,000)
// 2nd row ~ : int (-2^62 ~ 2^62) -> long long
// most frequent int (same freq -> smaller)
// 2910 -> earlier input first

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n;
long long num;
int res;
int maxf=0;
//map <int, int> freq; 
/*
bool comp(pair<int, int> &a, pair<int, int> &b){
    if (a.second == b.second) // freq 동일하면
        return a<b; // 크기 순으로
    else
        return a.second > b.second; // freq 대로 정렬 
}*/
int freq(vector<long long> v){ // arr[]= *arr, &
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (v[i]==v[i+1])
            cnt++;
            if (maxf < cnt){
                maxf = cnt;
                res = v[i];
        }
        else cnt=0;
    return cnt;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    vector <long long> v(n); // input n 정보 -> in main
    
    for(int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
        //freq[num]++; //+= 1;
        /*if (maxf < freq(v)){
            maxf = freq(v);
            res = v[i];
        }*/
        res = freq(v);
    }
    cout<< res;

    return 0;
}

// https://fishersheep.tistory.com/166