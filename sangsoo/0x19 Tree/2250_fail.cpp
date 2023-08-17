/*
level 1의 거리 : 1
level 2의 거리 : leftmost child의 right children의 수 + right most child의 left children + 2 + lv1의 거리
level 3의 거리 : leftmost child의 right children의 수 + right most child의 left children + 2 + lv2의 거리
...
lelvel n의 거리 : leftmost child의 right children의 수 + right most child의 left children + 2 + lv(n-1)의 거리
... 라고 잘못생각해서 개망함.
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Tree{
private:
    int val;
    Tree *left, *right;
public:
    Tree(){val = 0; left = NULL; right = NULL;}
    void setData(int val){this->val = val;}
    void setLeft(Tree* left){this->left = left;}
    void setRight(Tree* right){this->right = right;}
    Tree* getLeft(){return left;}
    Tree* getRight(){return right;}
    int getVal(){return val;}
};

int count_with_bfs(Tree* node){
    if(!node) return 0;
    int cnt = 1;
    cout << "node -> getVal() : " << node->getVal() << endl;
    queue<Tree*> q;
    q.push(node);
    while (!q.empty()){
        Tree* cur = q.front(); q.pop();
        cnt++;
        cout << "cnt : " << cnt << endl;
        if(cur->getLeft())
            q.push(cur->getLeft());
        if(cur->getRight())
            q.push(cur->getRight());
    }
    return cnt;
}

vector<vector<Tree*>> level_partition(Tree* t){
    queue<Tree*> q;
    q.push(t);
    cout << "t : " << t->getVal() << endl;
    vector<vector<Tree*>> vv; vector<Tree*> v;
    v.push_back(t);  vv.push_back(v);
    while(!q.empty()){
        vector<Tree*> level; int lv_size = q.size();
        cout << "* lv_size : " << lv_size << endl;
        for(int i = 0; i < lv_size; i++){
            Tree* cur = q.front(); q.pop();
            cout << "cur : " << cur->getVal() << " lv_size : " << lv_size << endl;
            if (cur->getLeft()){
                level.push_back(cur->getLeft());
                q.push(cur->getLeft());
                cout << "cur->getLeft() : " << cur->getLeft()->getVal() << endl;
            }
            if (cur->getRight()){
                level.push_back(cur->getRight());
                q.push(cur->getRight());
                cout << "cur->getRight() : " << cur->getRight()->getVal() << endl;
            }
        }
        vv.push_back(level);
    }
    return vv;
}

int lv_dist[10002]; // level마다 distance 저장
int n;
Tree* leftmost[10002]; // level마다 leftmost node 저장
Tree* rightmost[10002]; // level마다 rightmost node 저장
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Tree* tree = new Tree[n+1]; // int *array = new int[length]; 

    for(int i = 0; i < n; i++){
        int val, left, right;
        cin >> val >> left >> right;
        tree[val].setData(val);
        if(left != -1)
            tree[val].setLeft(&tree[left]);
        else    
            tree[val].setLeft(NULL);
        if(right != -1)
            tree[val].setRight(&tree[right]);
        else    
            tree[val].setRight(NULL);
    }
    cout << tree[2].getVal() << endl;
    vector<vector<Tree*>> vv = level_partition(&tree[1]);
    int i = 1;
    for(auto v : vv){
        cout << "v[0] : " << v[0]->getVal() << endl;
        leftmost[i] = v.front(); // *min_element(v.begin(), v.end())
        rightmost[i] = v.back();
        cout << "v.front() : " << v.front()->getVal() << " v.back() : "<< v.back()->getVal() << endl;
        i++;
    }
    cout <<"**********" << endl;
    int lv = 1;
    lv_dist[lv] = 1;
    cout << "lv_dist[lv] : " << lv_dist[lv] << endl;
    int total_lv = vv.size();
    cout << "total_lv : " << total_lv << endl;
    for(lv = 2; lv <= total_lv; lv++){
        lv_dist[lv] = 2 + lv_dist[lv-1] + count_with_bfs(leftmost[lv]) + count_with_bfs(rightmost[lv]);
    }
    int mx = 0; int mxlv = 0;
    for(int i = 1; i <= n; i++){
        if (mx < lv_dist[i]) {
            mx = lv_dist[i];
            mxlv = i;
        }
    }
    cout << mxlv << " " << mx;
}