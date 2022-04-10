#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main(){
    int set[10] = {0,1,2,3,4,5,6,7,8,9};
    int stack[10] = {0,0,0,0,0,0,0,0,0,0};

    string str; cin>>str;
    stringstream ss(str);
    char t;

    int cur;
    while(ss>>t){
        cur = (int) t - 48;
        if(cur==6||cur==9) stack[6] ++;
        else stack[cur] ++;
    }
    int max = ceil(((float) stack[6] + (float)stack[9])/2);
    stack[6] = 0; stack[9] = 0;
    for(int i=0; i<10; ++i){
        if (max <= stack[i])
            max = stack[i];
    }
    cout << max;   
        
}