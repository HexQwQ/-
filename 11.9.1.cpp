#include "binary_tree.h"

BiTreeNode* CreatBiTree(char* s, int &i, int len)
{
	if( i >= len )  return NULL;
	if( s[i] == '#' )  
	{
		i++;
		return NULL;
	}
    BiTreeNode *root = new BiTreeNode(s[i++]);
    root->left = CreatBiTree(s, i, len);         
    root->right = CreatBiTree(s, i, len);        
	return root;
}

void InOrder(BiTreeNode* root)
{

    if( root == NULL )
        return ;
    InOrder(root->left);
	printf("%c",root->data);
    InOrder(root->right);
}
