#include <bits/stdc++.h> 
/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
    
********************************************************************/

void getPath(BinaryTreeNode<int> *root, string str, vector<string> &paths){
    str += to_string(root->data) + " ";

    if(root->left == NULL && root->right == NULL){
        paths.push_back(str);
        return;
    }

    if(root->left != NULL){
        getPath(root->left, str, paths);
    }
    
    if(root->right != NULL){
        getPath(root->right, str, paths);
    }
}

vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root == NULL){
        return {};
    }

    vector<string> paths;
    
    getPath(root, "", paths);
    return paths;
}
