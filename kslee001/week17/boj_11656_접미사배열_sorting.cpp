// https://www.acmicpc.net/problem/11656 접미사배열
#include <iostream>
#include <sstream>
using namespace std;

string arr[1000];
string sorted[1000];
void merge(string* arr, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = start;
    while(i<=mid && j<= end){
        bool flag = false;
        for(int a=0,b=0; a<arr[i].size() && b<arr[j].size(); ++a, ++b){
            char c1 = arr[i][a];
            char c2 = arr[j][b];
            if(c1 == c2) continue;
            if(c1 < c2){
                sorted[k++] = arr[i++];
                flag = true;
                break;
            }
            else{
                sorted[k++] = arr[j++];
                flag = true;
                break;
            }
        }
        if(!flag){
            if(arr[i].size() < arr[j].size())
                sorted[k++] = arr[i++];
            else
                sorted[k++] = arr[j++];
        }
    }
    while(i<=mid)
        sorted[k++] = arr[i++]; 
    while(j<=end)
        sorted[k++] = arr[j++];
    for(int x=start; x<=end; ++x)
        arr[x] = sorted[x];
}   
void msort(string* arr, int start, int end){
    if(start>=end) return;
    int mid = (start+end)/2;
    msort(arr, start, mid);
    msort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    string str;
    cin >>str;
    int n = str.size();

    // 입력
    for(int i=0; i<n; ++i){
        arr[i] = str.substr(i);
    }
    msort(arr, 0, n-1);
    for(int i=0; i<n-1; ++i)
        cout << arr[i] << "\n";
    cout << arr[n-1];


}