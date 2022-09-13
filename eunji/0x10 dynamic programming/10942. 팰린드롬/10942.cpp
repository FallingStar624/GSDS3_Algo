/*
문제 : 
자연수 N개, 질문을 총 M번
각 질문은 두 정수 S와 E(1 ≤ S ≤ E ≤ N)로 나타낼 수 있으며,
S번째 수부터 E번째까지 수가 팰린드롬을 이루는지를 물어봄.
팰린드롬은 앞 뒤를 뒤집어도 똑같은 문자열

Input : 
자연수 N (1 ≤ N ≤ 2,000)
자연수 N개 순서대로 (<=100,000)
질문 M (1 ≤ M ≤ 1,000,000)
질문 S와 E가 한 줄에 하나씩

Output : 
각 질문에 대한 대답
팰린드롬인 경우에는 1, 아닌 경우에는 0을 출력
*/

#include <iostream>
using namespace std;

int N;
int M;
int ar[2002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> ar[i]; 
    }
    cin >> M;
    
    for (int i=0; i<M; i++){ // 시간 초과
        int S = 0, E = 0;
        int answer = 1;
        cin >> S >> E;
        if ((S - E) % 2 == 0) { // 홀수 길이
            // printf("%d\n", (E-S)/2);
            for (int j=1; j<=((E-S)/2); j++){
                // ar[가운데+1] == ar[가운데-1]
                if (ar[((S+E)/2)+j] != ar[((S+E)/2)-j]){
                    // cout << ar[((S+E)/2)+j]<< ' ' << ar[((S+E)/2)-j] << '\n';
                    answer = 0;
                }
            }
        }
        else  { // 짝수 길이
            // printf("%d\n", (E-S+1)/2);
            for (int j=1; j<=((E-S+1)/2); j++){
                if (ar[((S+E+1)/2)+j-1] != ar[((S+E+1)/2)-j]){
                    // cout << ar[((S+E+1)/2)+j-1] << ' ' << ar[((S+E+1)/2)-j] << '\n';
                    answer = 0; 
                }
            }
        }
        cout << answer << '\n';
    }
    return 0;
}


/* -----시간 초과------ */
// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> N;
//     for (int i=1; i<=N; i++){
//         cin >> ar[i]; 
//     }
//     cin >> M;
    
//     for (int i=0; i<M; i++){ // 시간 초과
//         int S = 0, E = 0;
//         int answer = 1;
//         cin >> S >> E;
//         if ((S - E) % 2 == 0) { // 홀수 길이
//             // printf("%d\n", (E-S)/2);
//             for (int j=1; j<=((E-S)/2); j++){
//                 // ar[가운데+1] == ar[가운데-1]
//                 if (ar[((S+E)/2)+j] != ar[((S+E)/2)-j]){
//                     // cout << ar[((S+E)/2)+j]<< ' ' << ar[((S+E)/2)-j] << '\n';
//                     answer = 0;
//                 }
//             }
//         }
//         else  { // 짝수 길이
//             // printf("%d\n", (E-S+1)/2);
//             for (int j=1; j<=((E-S+1)/2); j++){
//                 if (ar[((S+E+1)/2)+j-1] != ar[((S+E+1)/2)-j]){
//                     // cout << ar[((S+E+1)/2)+j-1] << ' ' << ar[((S+E+1)/2)-j] << '\n';
//                     answer = 0; 
//                 }
//             }
//         }
//         cout << answer << '\n';
//     }
//     return 0;
// }