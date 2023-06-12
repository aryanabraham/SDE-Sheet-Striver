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
void inOrderTraversal(TreeNode *root, vector<int>& inOrderNodes){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left, inOrderNodes);
    inOrderNodes.push_back(root->data);
    inOrderTraversal(root->right, inOrderNodes);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> inOrderNodes;

    inOrderTraversal(root, inOrderNodes);
    return inOrderNodes;
}
