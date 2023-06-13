#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void preOrderUtils(int level, TreeNode<int> *curr, vector<int>& leftViewNodes){
    if(curr == NULL){
        return;
    }
    
    if(level == leftViewNodes.size()){
        leftViewNodes.push_back(curr->data);
    }
    
    preOrderUtils((level + 1), (curr->left), leftViewNodes);    
    preOrderUtils((level + 1), (curr->right), leftViewNodes);    
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    int level = 0;
    vector<int> leftViewNodes;
    TreeNode<int> *curr = root;

    preOrderUtils(level, curr, leftViewNodes);
    return leftViewNodes;
}
