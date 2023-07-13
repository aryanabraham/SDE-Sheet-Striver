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

int getDiameter(int &maxHeight, TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = getDiameter(maxHeight, root->left);
    int rightHeight = getDiameter(maxHeight, root->right);

    maxHeight = max(maxHeight, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(root == NULL){
        return 0;
    }

    int maxHeight = 0;
    getDiameter(maxHeight, root);

    return maxHeight;
}
