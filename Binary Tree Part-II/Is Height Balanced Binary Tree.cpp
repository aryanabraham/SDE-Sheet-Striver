#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int getHeight(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if(leftHeight == -1 || rightHeight == -1){
        return -1;
    }
    
    if(abs(leftHeight - rightHeight) > 1){
        return -1;
    }  
    
    return 1 + max(leftHeight, rightHeight);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(root == NULL){
        return true;
    }
    
    return (getHeight(root) == -1) ? false : true;
    
}
