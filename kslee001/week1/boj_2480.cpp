#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int res;
    int a,b,c; cin>>a>>b>>c;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    int max_v = *max_element(v.begin(), v.end());

    int num_a = count(v.begin(), v.end(), a);
    int num_b = count(v.begin(), v.end(), b);
    int num_c = count(v.begin(), v.end(), c);
    int num_arr[3] = {num_a,num_b,num_c};


    for (int i = 0; i<3; i++ ){
        if(num_arr[i]==3){
            res = 10000 + v[i]*1000;
            break;
        }
        else if(num_arr[i]==2){
            res = 1000 + v[i]*100;
            break;
        }
        else{
            res = max_v*100;
        }
    }   
    cout << res;
}