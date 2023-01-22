#include <iostream> 
#include <list> 

using namespace std; 
  
int main() 
{ 
    // 리스트 생성 
    list<int> a;  
 
    // 원소 추가 
    a.push_back(22); 
    a.push_back(33); 
    a.push_front(11); 
    a.push_back(44); 
    a.push_back(55); 
  
    // 반복자 생성 
    list<int>::iterator iter = a.begin(); 
 
    // 리스트 출력 
    for(iter=a.begin(); iter!=a.end(); iter++) 
    { 
        cout << *iter << " "; // 원본 리스트: 11 22 33 44 55 
    } 
 
    cout << "" << endl; 
    cout << "" << endl; 
  
    // 원소 삭제 
    a.pop_front(); 
    a.pop_back(); 
     
    for(iter=a.begin(); iter!=a.end(); iter++) 
    { 
        cout << *iter << endl; // 원소 삭제후 리스트: 22 33 44 
    } 
  
    cout << "" << endl; 
    
    // 리스트 사이즈 출력 
    cout << a.size() << endl; // 3 출력( 22, 33, 44 이므로) 
  
    // 리스트가 비어있는가 
    cout << a.empty() << endl; // 비어있지 않으므로 0 반환 
      
    // 리스트 첫번째 원소 출력 
    cout << a.front() << endl; // 22 
  
    // 리스트 마지막 원소 출력 
    cout << a.back() << endl; // 44 
  
    cout << "" << endl; 
 
    // 반복자 2번째 위치로 이동 
    iter++; // 반복자가 두번째 원소(33)를 가리킴 
    iter++; // 반복자가 세번째 원소(44)를 가리킴 
    a.insert(iter, 55555); 
    for(iter=a.begin(); iter!=a.end(); iter++) 
    { 
        cout << *iter << endl; //세번째 원소(44) 전에 추가하는 것(22,55555,33,44) 
    }  
}
  