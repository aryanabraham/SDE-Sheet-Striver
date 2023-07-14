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

 

int lowestCommonAncestor(TreeNode<int> *root, int x, int y){

    //    Write your code here

    if(root == NULL){
        return -1;
    }

    if(root->data == x || root->data == y){
        return root->data;
    }

    int leftChild = lowestCommonAncestor(root->left, x, y);
    int rightChild = lowestCommonAncestor(root->right, x, y);

    if(leftChild == -1){
        return rightChild;
    }

    else if(rightChild == -1){
        return leftChild;
    }
    return root->data;
}
