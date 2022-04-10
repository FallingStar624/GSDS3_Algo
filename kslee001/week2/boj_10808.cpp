#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string str; cin >>str;
    stringstream ss(str);
    char t; int len = 0;
    while (ss>>t) len++; ss.clear(); ss.str(str);

    char a = 'a'; char z= 'z';
    int arr_size = (int) z - (int) a + 1;
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++){
        arr[i] = 0;
    }

    int idx;
    while (ss>>t)
    {
        idx = (int) t - 97;
        arr[idx] ++;
    }

    for(int i=0; i<arr_size; ++i){
        cout << arr[i];
        if(i!=arr_size-1) cout << " ";
    }
    
}