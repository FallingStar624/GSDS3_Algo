/*
회원들을 나이가 증가하는 순으로,
나이가 같으면 먼저 가입한 사람이 앞에 오게 정렬

INPUT :
- 온라인 저지 회원의 수 N (1 ≤ N ≤ 100,000)
- 회원 나이, 공백, 이름 (1<나이<=200, 이름 : 알파벳대소문자 길이<=100)
- 입력순 = 가입순
*/

#include <iostream>

using namespace std;

int N;
int age[100002];
string name[100002];
int age2[100002];
string name2[100002];

void merge(int st, int en){
  int mid = (st+en)/2;
  int ldx = st;
  int rdx = mid;
  for (int i=st; i<en; i++){
    if (ldx == mid) {
      age2[i] = age[rdx]; 
      name2[i] = name[rdx++];
    }
    else if (rdx == en){
      age2[i] = age[ldx]; 
      name2[i] = name[ldx++];
    }
    else if (age[ldx] > age[rdx]) {
      age2[i] = age[rdx]; 
      name2[i] = name[rdx++];
    }
    else if (age[ldx] <= age[rdx]) {
      age2[i] = age[ldx]; 
      name2[i] = name[ldx++];
    }
  }
  for (int i=st; i<en; i++){
    age[i] = age2[i];
    name[i] = name2[i];
  }
}

void merge_sort(int st, int en){
  if (en <= st+1) return;
  int mid = (st+en)/2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, en);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> age[i] >> name[i];
  }

  merge_sort(0, N);

  for (int i=0; i<N; i++){
    cout << age[i] << ' ' << name[i] << '\n';
  }
}
