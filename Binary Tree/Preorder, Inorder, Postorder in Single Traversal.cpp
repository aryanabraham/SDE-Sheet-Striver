#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    if(root == NULL){
        return {};
    }
    
    vector<int> inOrderNodes;
    vector<int> preOrderNodes;
    vector<int> postOrderNodes;
    stack<pair<BinaryTreeNode<int> *, int>> st;

    st.push({root, 1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        int stage = it.second;
        BinaryTreeNode<int> *node = it.first;

        if(stage == 1){
            preOrderNodes.push_back({node->data});
            st.push({node, (stage + 1)});
            
            if(node->left != NULL){
                st.push({node->left, 1});
            }
        }

        else if(stage == 2){
            inOrderNodes.push_back({node->data});
            st.push({node, (stage + 1)});

            if(node->right != NULL){
                st.push({node->right, 1});
            }
        }
        
        else{
            postOrderNodes.push_back({node->data});
        }
    }
    return {inOrderNodes, preOrderNodes, postOrderNodes};
}
