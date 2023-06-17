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

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> verticalNodes;
    map<int, vector<int>> mpp;
    queue<pair<TreeNode<int> *, int>> q; 

    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int line = it.second;
        TreeNode<int> *node = it.first;
        mpp[line].push_back(node->data);

        if(node->left != NULL){
            q.push({node->left, (line - 1)});
        }
        if(node->right != NULL){
            q.push({node->right, (line + 1)});
        }
    }

    for(auto it: mpp){
        for(int i = 0; i < (it.second).size(); i++){
            verticalNodes.push_back(it.second[i]);
        }
    }
    return verticalNodes;
}
