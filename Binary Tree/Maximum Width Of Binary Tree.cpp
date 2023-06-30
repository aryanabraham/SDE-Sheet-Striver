#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root == NULL){
        return 0;
    }
    
    int maxWidth = 0;
    queue<TreeNode<int> *> q;

    q.push(root);
    while(!q.empty()){
        int queueSize = q.size();
        maxWidth = max(maxWidth, queueSize);

        for(int i = 0; i < queueSize; i++){
            TreeNode<int> *node = q.front();

            if(node->left != NULL){
                q.push(node->left);
            }

            if(node->right != NULL){
                q.push(node->right);
            }
           q.pop();
        }    
    }
    return maxWidth;
}
