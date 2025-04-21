#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;

    node(int value) : val(value), left(NULL), right(NULL){}
};

void push(node*& root, int k){
    if(root == NULL){
        root = new node(k);
    }else  if(k < root->val){
        push(root->left, k);
    }else{
        push(root->right, k);
    }
}
void duyet(node* root) {
    if (root != NULL) {
        duyet(root->left);
        cout << root->val << endl;
        duyet(root->right);
    }
}
void duyet2(node* root){
    stack<node*> s;
    node* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->val << " ";
        current = current->right;
    }
}

int main(){
    node* root = NULL;
    push(root, 5);
    push(root, 2);
    push(root, 4);
    push(root, 6);
    push(root, 3);
    push(root, 7);
    duyet2(root);
    return 0;
}