#include "binary_tree.h"

BiTreeNode* BiTreeChangeStack(BiTreeNode* root)
{
    if( root == NULL )  return NULL;
	BiTreeNode *l,*r;
    l = BiTreeChangeStack(root->left);
	r = BiTreeChangeStack(root->right);
    root->left = r;
	root->right = l;
	return root;
}

void PostOrder(BiTreeNode* root)
{
    if( root == NULL )  return ;
	PostOrder(root->left);
    PostOrder(root->right);
    printf("%c",root->data);
}
