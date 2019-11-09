#include "binary_tree.h"

int Max(int a,int b){
	return a > b ? a : b;
}

int GetTreeDepth(BiTreeNode* root)
{
	if( root == NULL )  return 0;
    return Max(GetTreeDepth(root->left),GetTreeDepth(root->right))+1;
}

int GetNodeNumber(BiTreeNode* root)
{
	if( root == NULL )  return 0;
    return GetNodeNumber(root->left)+GetNodeNumber(root->right)+1;
}

int GetLeafNodeNumber(BiTreeNode* root)
{
	if( root == NULL )  return 0;
	if( root->left == NULL && root->right == NULL )  return 1;
    return GetLeafNodeNumber(root->left) + GetLeafNodeNumber(root->right);
}

