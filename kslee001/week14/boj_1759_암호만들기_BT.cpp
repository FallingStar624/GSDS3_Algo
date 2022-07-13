#include <bits/stdc++.h>
using namespace std;

// boj_1759_암호만들기_BT


int n; // 길이
int c; // 문자 종류

char print[15];
bool used [15];

int  raw[15];
char sorted[15];

int conso_cnt = 0; // 자음 개수
int vowel_cnt = 0; // 모음 개수
   
void input(){
    cin >> n >> c;
    char input;
    for(int i=0; i<c; ++i){
        cin >> input;
        raw[i] = (int)input;
    }
    sort(raw, raw+c);
    for(int i=0; i<c; ++i){
        sorted[i] = (char) raw[i];
    }
}

void counter1(char c){       // 모음개수, 자음개수 세는 함수
    if     (c == 'a') vowel_cnt++;
    else if(c == 'e') vowel_cnt++;
    else if(c == 'i') vowel_cnt++;
    else if(c == 'o') vowel_cnt++;
    else if(c == 'u') vowel_cnt++;
    else conso_cnt ++;
}

void counter2(char c){       // prev 확인한 뒤 모음개수, 자음개수 수정하는 함수
    if     (c == 'a') vowel_cnt--;
    else if(c == 'e') vowel_cnt--;
    else if(c == 'i') vowel_cnt--;
    else if(c == 'o') vowel_cnt--;
    else if(c == 'u') vowel_cnt--;
    else conso_cnt--;
}

void func(int k, int prev_idx){
    if(k==n){
        if( conso_cnt >=2 && vowel_cnt >=1 ){
            for(int i=0; i<n; ++i){
                printf("%c", print[i]);
            }printf("\n");
        }
        return;
    }

    char prev = '0';   // 처음 시작하는 '문자'
    for(int i=prev_idx+1; i<c; ++i){
        if(prev != sorted[i]){
            print[k] = sorted[i];
            prev = sorted[i];
            counter1(sorted[i]);
            func(k+1, i);
            counter2(prev);   // prev 함수 빼기
        }
    }
}

int main(){
    input();
    func(0, -1);
}