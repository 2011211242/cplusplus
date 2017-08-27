/****************************************
* File Name: main.cpp
* Created Time: 2017-08-28 00:08:53
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/

#include <cstdio>
#include <stack>
using namespace std;

struct node{
    node():left(NULL), right(NULL), val(0), visited(false){}
    node(int k):left(NULL), right(NULL), val(k), visited(false){}
    node * left, *right;
    bool visited;
    int val;
};

void preorder_travel(node * root){
    stack<node *> stk;
    while(root || !stk.empty()){
        while(root){
            printf("%d ", root -> val);
            stk.push(root -> right);
            root = root -> left;
        }
        root = stk.top();
        stk.pop();
    }
}

void inorder_travel(node * root){
    stack<node *> stk;
    while(root || !stk.empty()){
        while(root){
            stk.push(root);
            root = root -> left;
        }

        root = stk.top();
        stk.pop();
        printf("%d ", root->val);
        root = root -> right;
    }
}

void postorder_travel(node *root){
    if(root == NULL) return;
    stack<node *> stk;
    stk.push(root);
    root = root -> left;

    while(!stk.empty()){
        while(root && root -> visited == false){
            stk.push(root);
            root = root -> left;
        }
        root = stk.top();
        if(root -> right == NULL || root -> right -> visited){
            printf("%d ", root -> val);        
            root -> visited = true;
            stk.pop();
        }
        root = root->right;
    }
}

int main(){
    node a;
    node * root = new node(4); 
    root ->left = new node(2);

    root -> left -> left = new node(1);
    root -> left -> right = new node(3);

    root -> right = new node(5);
    root -> right -> right = new node(7);
    root -> right -> right -> left = new node(6);

    inorder_travel(root);
    printf("\n");
    preorder_travel(root);
    printf("\n");
    postorder_travel(root);
    printf("\n");

    return 0;
}
