#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int arr[9]; int temp;
    int sum;
    for(int i=0; i<9; ++i){
        cin >>temp;
        arr[i] = temp;
        sum += temp;
    }

    int first, second;
    for(int i=0; i<9; ++i){
        first = arr[i];
        bool flag = false;
        for(int j=0; j<9; ++j){
            if(i==j){
                continue;
            }
            else{
                second = arr[j];
                if(sum-first-second == 100){
                    flag = true;
                    break;
                }
            }
        }
        if(flag == true){
            break;
        }
    }

    // sorting
    for(int i=1; i<9; ++i){
        int right = i;
        int left = i-1;
        while(left>=0 && arr[right]<arr[left]){
            swap(arr[right], arr[left]);
            right--;
            left--;
        }
    }

    int idx = 0;
    for(int i=0; i<9; ++i){
        if(arr[i]!=first && arr[i]!=second){
            idx++;
            cout << arr[i];
        }
        else{
            continue;
        }
        if(idx == 7){
            break;
        }
        else{
             cout<<"\n";
        }
    }
    


    


}