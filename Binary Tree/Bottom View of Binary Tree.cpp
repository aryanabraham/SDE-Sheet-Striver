#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    map<int, int> mpp;
    vector<int> bottomViewNodes;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();

        int line = it.second;
        BinaryTreeNode<int> * node = it.first;

        mpp[line] = (node->data);

        if(node->left != NULL){
            q.push({(node->left), (line - 1)});
        }

        if(node->right != NULL){
            q.push({(node->right), (line + 1)});
        }
        q.pop();
    }

    for(auto &it: mpp){
        bottomViewNodes.push_back(it.second);
    }
    return bottomViewNodes;
}
