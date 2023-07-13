#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/
bool getPath (int x, TreeNode<int> *node, vector<int>& path){
	if(node == NULL){
		return false;
	}

	path.push_back(node->data);

	if(node->data == x){
		return true;
	}

	if(getPath(x, node->left, path) || getPath(x, node->right, path)){
		return true;
	}
	
	path.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	if(root == NULL){
		return {};
	}
	
	vector<int> path;
	TreeNode<int> *node = root;
	
	getPath(x, node, path);
	return path;	
}
