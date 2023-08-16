#include <iostream>
#include <unordered_map>
using namespace std;

int n;
char p, l, r;

unordered_map<char, char> leftChild;
unordered_map<char, char> rightChild;

void preorder(char parent) {
    if (parent == '.') return;
    cout << parent;
    preorder(leftChild[parent]);
    preorder(rightChild[parent]);
}

void postorder(char parent) {
    if (parent == '.') return;
    postorder(leftChild[parent]);
    cout << parent;
    postorder(rightChild[parent]);
}

void inorder(char parent) {
    if (parent == '.') return;
    inorder(leftChild[parent]);
    inorder(rightChild[parent]);
    cout << parent;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> p >> l >> r;
        leftChild[p] = l;
        rightChild[p] = r;
    }

    preorder('A'); cout << endl;
    postorder('A'); cout << endl;
    inorder('A');

    return 0;
}
