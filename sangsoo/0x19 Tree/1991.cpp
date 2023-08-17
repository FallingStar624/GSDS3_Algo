#include <iostream>
#include <string>
using namespace std;

class Tree{
private:
    string data;
    Tree *left, *right;
public:
    Tree() {data = ""; left = NULL; right = NULL;} // constructor
    void setData(char data){this->data = data;}
    void setLeft(Tree* l){this->left = l;}
    void setRight(Tree* r){this->right = r;}

    void static preorder(Tree* node){ // static을 붙여줘야 recursive하게 사용 가능
        if (!node) return;
        cout << node->data;
        preorder(node->left);
        preorder(node->right);
    }
    void static inorder(Tree* node){
        if (!node) return;
        inorder(node->left);
        cout << node->data;
        inorder(node->right);
    }
    void static postorder(Tree* node){
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data;
    }
};

int main(){
    int n;
    cin >> n;
    Tree* tree = new Tree[n]; // int *array = new int[length]; 
    for(int i = 0; i < n; i++){
        char data, left, right;
        cin >> data >> left >> right;
        if(data != '.')
            tree[(int)(data-'A')].setData(data);
        if(left != '.')
            tree[(int)(data - 'A')].setLeft(&tree[(int)(left-'A')]);
        else
            tree[(int)(data - 'A')].setLeft(NULL);
        if(right != '.')
            tree[(int)(data - 'A')].setRight(&tree[(int)(right - 'A')]);
        else 
            tree[(int)(data - 'A')].setRight(NULL);
    }
    Tree* root = &tree[0];
    Tree::preorder(root);
    cout << '\n';
    Tree::inorder(root);
    cout << '\n';
    Tree::postorder(root);
}