/*
1. root 찾기
2. inorder 값 저장
3. level partition해서 최대 최소 inorder 차이 구하기.
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Tree{
public:
    int val;
    int inorderval;
    Tree *left, *right;
    Tree(){val = 0; left = NULL; right = NULL;}

};

vector<vector<Tree*>> level_partition(Tree* t){
    queue<Tree*> q;
    q.push(t);
    vector<vector<Tree*>> vv; vector<Tree*> v;
    v.push_back(t);  vv.push_back(v);
    while(!q.empty()){
        vector<Tree*> level; int lv_size = q.size();
        for(int i = 0; i < lv_size; i++){
            Tree* cur = q.front(); q.pop();
            if (cur->left){
                level.push_back(cur->left);
                q.push(cur->left);
            }
            if (cur->right){
                level.push_back(cur->right);
                q.push(cur->right);
            }
        }
        vv.push_back(level);
    }
    return vv;
}

int inordercnt = 1;
void static inorder(Tree* t){
    if (t == NULL) return; // Base case: if the node is NULL, return
    inorder(t->left);
    t->inorderval = inordercnt;
    inordercnt++;
    inorder(t->right);
}

int lv_dist[10002]; // level마다 distance 저장
int n;
int find_root[10002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Tree* tree = new Tree[n+1]; // int *array = new int[length]; 

    for(int i = 0; i < n; i++){
        int val, left, right;
        cin >> val >> left >> right;
        find_root[left] = 1; find_root[right] = 1;
        tree[val].val = val;
        if(left != -1)
            tree[val].left = &tree[left];
        else    
            tree[val].left = NULL;
        if(right != -1)
            tree[val].right = &tree[right];
        else    
            tree[val].right = NULL;
    }
    // root 찾기
    int root;
    for(int i = 1; i <=n; i++){
        if (find_root[i] == 0)
            root = i;
    }


    inorder(&tree[root]);
    vector<vector<Tree*>> vv = level_partition(&tree[root]);
    int mx_lv_dist = 0;
    int i = 0; int mx_idx = 0;
    for (auto& level : vv) {
        i += 1;
        int mx = 0; int mn = 10002;
        for (auto node : level) {
            if (node->inorderval > mx) mx = node->inorderval;
            if (node->inorderval < mn) mn = node->inorderval;
        }
        if (mx_lv_dist < mx-mn+1){
            mx_lv_dist = mx-mn+1;
            mx_idx = i;
        }
    }
    cout << mx_idx << " " << mx_lv_dist;

}