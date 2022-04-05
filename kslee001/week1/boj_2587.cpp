#include <iostream>
using namespace std;
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp; 
}

int main(){
    int a,b,c,d,e; cin>>a>>b>>c>>d>>e;
    int arr[5] = {a,b,c,d,e};
    // insertion sort
    for(int i=1; i<5; ++i){
        int right = i;
        int left = i-1;
        int target = arr[right];
        while(left>=0 && arr[right]<arr[left]){
            swap(arr[left], arr[right]);
            right--;
            left --;
        }
    }
    int mean = a+b+c+d+e; mean = mean/5;
    int median = arr[2];
    cout << mean <<"\n" << median;
}