#include <iostream>
#include <algorithm>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

void inorder(TreeNode *root);
void preorder(TreeNode * root);
void postorder(TreeNode * root);
int evaluate(TreeNode * exp);
int calc_direc_size(TreeNode *root);
int get_node_count(TreeNode *node);
int get_height(TreeNode *node);

int main(){
    //TreeNode *n1, *n2, *n3;

    //n1 = (TreeNode*)malloc(sizeof(TreeNode));
    //n2 = (TreeNode*)malloc(sizeof(TreeNode));
    //n3 = (TreeNode*)malloc(sizeof(TreeNode));

    //n1 -> data = 10;
    //n1 -> left = n2;
    //n1 -> right = n3;

    //n2 -> data = 20;
    //n2 -> left = NULL;
    //n2 -> right = NULL;

    //n3 -> data = 30;
    //n3 -> left = NULL;
    //n3 -> right = NULL;

    //cout << n1 -> data << endl; 
    //cout << n1 -> left -> data << endl; 
    //cout << n1 -> right -> data << endl; 

    //TreeNode n1 = {1, NULL, NULL};
    //TreeNode n2 = {4, &n1, NULL};
    //TreeNode n3 = {16, NULL, NULL};
    //TreeNode n4 = {25, NULL, NULL};
    //TreeNode n5 = {20, &n3, &n4};
    //TreeNode n6 = {15, &n2, &n5};
    //TreeNode *root = &n6;

    //inorder(root); cout << endl;
    //preorder(root); cout << endl;
    //postorder(root); cout << endl;

    TreeNode n1 = {1, NULL, NULL};
    TreeNode n2 = {4, NULL, NULL};
    TreeNode n3 = {'*', &n1, &n2};
    TreeNode n4 = {16, NULL, NULL};
    TreeNode n5 = {25, NULL, NULL};
    TreeNode n6 = {'+', &n4, &n5};
    TreeNode n7 = {'+', &n3, &n6};
    TreeNode *exp = &n7;

    cout << evaluate(exp) << endl;
    cout << get_node_count(exp) << endl;
    cout << get_height(exp) << endl;
}

void inorder(TreeNode * root){
    if ( root ) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}


void preorder(TreeNode * root){
    if ( root ) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}


void postorder(TreeNode * root){
    if ( root ) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}

int evaluate(TreeNode *root){
    if ( root == NULL )
        return 0;
    if ( root -> left == NULL && root -> right == NULL )
        return root -> data;
    else {
        int op1 = evaluate(root -> left);
        int op2 = evaluate(root -> right);
        switch(root -> data){
            case '+': return op1 + op2;
            case '-': return op1 - op2;
            case '*': return op1 * op2;
            case '/': return op1 / op2;
        }
    }
    return 0;
}

int calc_direc_size(TreeNode *root){
    int left_size, right_size;
    if (root) {
        left_size = calc_direc_size(root -> left); 
        right_size = calc_direc_size(root -> right); 
        return (root -> data + left_size + right_size);
    }
    return 0;
}

int get_node_count(TreeNode *node){
    if ( node != NULL ) {
        return 1 + get_node_count(node -> left) + get_node_count(node -> right);
    }
    return 0;
}

int get_height(TreeNode *node){
    if (node != NULL){
        return 1 + MAX(get_height(node -> left), get_height(node -> right));
    }
    return 0;
}

































































































