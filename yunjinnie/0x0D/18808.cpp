// 1st row : N by M 크기의 판, K개의 스티커
// 2nd row : 스티커 판 크기 R by C
// 그 다음 R*C만큼의 matrix 형태 input에 0, 1로 스티커 표시
// 이어서 그 다음 스티커 판 크기 ... 반복

// 90 degree rotation : (3, 2) -> (2, 3)
// (0, 0) -> (0, 2), (0, 1) -> (1, 2)
// (1, 0) -> (0, 1), (1, 1) -> (1, 1)
// (2, 0) -> (0, 0), (2, 1) -> (1, 0)
// 같은 row element들은 같은 col element로 이동
// 같은 col element들은 같은 row element로 이동
// x, y -> y, 2-x -> y, r-1-x
// x is row, y is column

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r[11], c[11];
int paper[41][41];
int sticker[100][11][11];
int ans;
//bool avail;

void rotate(int idx){
    int tmp[11][11];
    //copy
    for (int i=0; i<r[idx]; i++){
        for (int j=0; j<c[idx]; j++){
            tmp[j][r[idx]-1-i] = sticker[idx][i][j];
        }
    }
    swap(r[idx], c[idx]); // swap matrix dimension 

    for (int x=0; x<r[idx]; x++){
        for (int y=0; y<c[idx]; y++){
            sticker[idx][x][y] = tmp[x][y];
            //sticker[idx][x][y] = tmp[c[idx]-1-y][x];
        }
    }
}

bool isValid(int idx){
    // paper
    for (int i=0; i<n; i++){
        for (int j = 0; j<m; j++){
            // sticker
            bool check = true;
            for (int x=0; x<r[idx]; x++){
                if (!check)
                    break;
                for (int y=0; y<c[idx]; y++){
                    if (x+i>=n || y+j>=m){
                        check = false;
                        break;
                    }
                    else if (sticker[idx][x][y]==0)
                        continue;
                    else if (paper[x+i][y+j]==1){
                        check = false;
                        break;
                    }
                }
            }
            if (check) {
                //avail = true;
                for (int a=0; a<r[idx]; a++){
                    for (int b = 0; b<c[idx]; b++){
                        if (sticker[idx][a][b]==0)
                            continue;    
                        paper[a+i][b+j]=1;
                    }
                }
                return true;
            }
            //if (avail)
                //break;
        }
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
    cin>>n>>m>>k;

    /*for (int row = 0; row<n; row++){
        for (int col = 0; col<m; col++){
            paper[40][40] = 0;
        }
    } */
    int i = 0;
    while(i<k){
        cin >> r[i] >> c[i];
        for (int x = 0; x<r[i]; x++){
            for (int y = 0; y<c[i]; y++){
                cin>>sticker[i][x][y]; // 0, 1
            }
        }

        for (int rot=0; rot<4; rot++){
            if(isValid(i))
                break;
            rotate(i);
        }
        i++;
    }

    for (int row = 0; row<n; row++){
        for (int col = 0; col<m; col++){
            if (paper[row][col]==1)
                ans++;//=paper[row][col];
        }
    }

    cout<<ans<<'\n';
    return 0;
}

// https://seokjin2.tistory.com/110
// https://imnotabear.tistory.com/74