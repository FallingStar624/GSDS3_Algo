#include <iostream>
#include <vector>
#include <map>
using namespace std;

        // inputs    // positions       // inputs length              
void NGE(int arr[], int len){
    vector<int*> stack;
    for(int i=0; i<len;++i){
        // cout << "current : " << arr[i] << endl;
        if(stack.empty()){
            stack.push_back(arr+i);
            // cout << arr[i] << "'s address has been pushed "<< endl;
        }
        else if(*(stack.back()) < arr[i]){
            while(!stack.empty() && *(stack.back()) < arr[i]){
                // cout << *(stack.back()) << " popped //"<< " res val is "<<arr[i]<< endl;
                // cout << "res[" << i << "] = " << arr[i]<< endl;
                *(stack.back()) = *(arr+i);
                stack.pop_back();
            }
            stack.push_back(arr+i);
        }
        else{
            stack.push_back(arr+i);
            // cout << arr[i] << " pushed "<< endl;
        }
    }
    // 스택에 남아있는 애들은 모두 -1
    while(!stack.empty()){
        *(stack.back()) = -1;
        stack.pop_back();
    }
}


int main(){
    int n; cin >>n;
    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];    
    }
    NGE(arr, n);
    
    for(int i=0; i<n; ++i){
        cout << arr[i] << " ";
    }

}