#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(root == NULL){
        return {};
    }
    
    map<int, int> mpp;
    vector<int> topViewNodes;
    queue<pair<TreeNode<int> *, int>> q;

    q.push({root, 0});
    while(!q.empty()){
        auto queueFront = q.front();
        q.pop();

        int line = queueFront.second;
        TreeNode<int> *node = queueFront.first;

        // finding line in map
        
        auto it = mpp.find(line);

        if(it == mpp.end()){
            mpp[line] = (node->val);
        }

        // pushing children into queue

        if(node->left != NULL){
            q.push({(node->left), (line - 1)});
        }

        if(node->right != NULL){
            q.push({(node->right), (line + 1)});
        }
    }

    for(auto &it: mpp){
        topViewNodes.push_back(it.second);
    }
    return topViewNodes;
}
