#include <bits/stdc++.h>
using namespace std;

int N,K;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int arr[N+1],res[N+1];
    for (int i=1;i<N+1;i++)
    {
        cin >> K;
        arr[i]=K;//높이 저장
        res[i]=0;
    }
    stack<int> S;
    S.push(1);
    for (int i=2;i<N+1;i++) {
        if (arr[S.top()]>arr[i])
        {
            res[i]=S.top();
        }
        else
        {
            while (!S.empty())
            {
               if (arr[S.top()]>arr[i])
               {
                   res[i]=S.top();
                   break;
               }
               //cout << arr[S.top()] << " is deleted\n";
               S.pop();
            }
        }
        S.push(i);
        //cout<<arr[S.top()]<<"is top\n";
    }
    for (int i=1;i<N+1;i++) {cout<<res[i]<<' ';}
}



//.시간초과
//int main(void){
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cin >> N;
//    stack<int> S,temp;
//    int array[N];
//    for (int i=0;i<N;i++)
//    {
//        cin>>K;
//        array[i]=K;
//        int check=0;
//        for (int j=i-1;j>=0;j--)
//        {
//            if (array[j]>array[i])
//            {
//                check=j+1;
//                break;
//            }
//        }
//        cout<<check;
//        if (i<N-1) cout<<" ";
//    }
//
//}