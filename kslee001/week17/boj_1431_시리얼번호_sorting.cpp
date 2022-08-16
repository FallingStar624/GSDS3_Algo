#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int n;
// 길이, 숫자 합, 알파벳부분 저장할 struct 정의
struct serial{
    int len;
    int sum;
    string str;
    serial(){len=0;sum=0;str="";}
    serial(int a, int b, string c){len = a; sum = b; str = c;}
};
// struct 담아놓을 arr
serial arr[50];
// 정렬용 arr
serial sorted[50];

void init(){
    cin >>n;
    string input;
    stringstream ss;
    char c;         // stringstream 하나씩 잘라서 볼 변수
    int converted;  // c의 int 값 확인할 변수

    for(int i=0; i<n; ++i){
        // 1. 하나씩 input 받아옴 (input : string)
        cin >>input;
        // 2. 받아온 인풋을 stringstream으로 하나씩 잘라냄 (ss->c : char)
        ss.str(input);
        int len = 0;
        int sum = 0;
        while(ss >> c){
            // 3. 길이 알아내기
            ++len;
            // 4-1. 잘라낸 것이 숫자인지 알파벳인지 확인하기
            converted = (int) c;
            if(converted >=48 && converted <=57)
                // 4-2. 숫자라면 합한 값(sum) 구하기
                sum += converted-48;
        }
        // (stringstream 초기화 : 뒤에 올 input을 위해)
        ss.clear();
        // 5. 구해놓은 정보로 serial 만들어서 arr에 저장하기
        arr[i] = serial(len, sum, input);
    }
}

void merge(serial* arr, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = start;
    while(i<=mid && j<= end){
        // 1. len 비교
        if(arr[i].len < arr[j].len) 
            sorted[k++] = arr[i++];
        else if(arr[i].len > arr[j].len)
            sorted[k++] = arr[j++];
        // 2. len 비교 불가능할 때 sum 비교
        else{
            if(arr[i].sum < arr[j].sum)
                sorted[k++] = arr[i++];
            else if(arr[i].sum > arr[j].sum)
                sorted[k++] = arr[j++];
            // 3. sum 비교로도 안될 때 사전순 비교
            else{
                // len 비교는 위(1.)에서 했기 때문에, 
                // 이곳에서 str size는 arr[i]와 arr[j]가 동일함
                int str_size = arr[i].str.size();
                for(int idx=0; idx < arr[i].str.size(); ++idx){
                    char c1 = arr[i].str[idx];
                    char c2 = arr[j].str[idx];
                    if(c1 == c2) continue;
                    if(c1 < c2){
                        sorted[k++] = arr[i++];
                        break;
                    }
                    if(c1 > c2){
                        sorted[k++] = arr[j++];
                        break;
                    }
                } 
            }
        }
    }
    while(i<=mid)
        sorted[k++] = arr[i++]; 
    while(j<=end)
        sorted[k++] = arr[j++];
    for(int x=start; x<=end; ++x)
        arr[x] = sorted[x];
}   
void msort(serial* arr, int start, int end){
    if(start>=end) return;
    int mid = (start+end)/2;
    msort(arr, start, mid);
    msort(arr, mid+1, end);
    merge(arr, start, mid, end);
}


int main(){
    init();
    msort(arr, 0, n-1);
    for(int i=0; i<n-1; ++i){
        cout << arr[i].str << "\n";
    }
    cout << arr[n-1].str;

}
