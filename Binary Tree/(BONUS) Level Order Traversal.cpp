#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(root == NULL){
        return {};
    }

    vector<int> levelOrderNodes;
    queue<BinaryTreeNode<int> *> q;

    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int> *node = q.front();
        q.pop();

        levelOrderNodes.push_back(node->val);

        if(node->left != NULL){
            q.push(node->left);
        }

        if(node->right != NULL){
            q.push(node->right);
        }
    }
    return levelOrderNodes;
}
