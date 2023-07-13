#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    if(root == NULL){
        return {};
    }

    bool flag = false;
    vector<int> zigzagNodes;
    queue<TreeNode<int> *> q;

    q.push(root);
    while(!q.empty()){
        int queueSize = q.size();
        vector<int> temp;

        for(int i = 0; i < queueSize; i++){
            TreeNode<int> *node = q.front();
            q.pop();

            if(node->left != NULL){
                q.push(node->left);
            }

            if(node->right != NULL){
                q.push(node->right);
            }
            temp.push_back(node->data);
        }

        if(flag){
            reverse(temp.begin(), temp.end());
        }

        for(int i = 0; i < temp.size(); i++){
            zigzagNodes.push_back(temp[i]);
        }
        flag = !flag;
    }
    return zigzagNodes;
}
