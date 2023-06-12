#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void preOrderTraversal(TreeNode *root, vector<int>& nodes){
    if(root == NULL){
        return;
    }

    nodes.push_back(root->data);
    preOrderTraversal(root->left, nodes);
    preOrderTraversal(root->right, nodes);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> nodes;

    preOrderTraversal(root, nodes);
    return nodes;
}
