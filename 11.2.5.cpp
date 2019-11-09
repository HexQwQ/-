  #include "binary_tree.h"

void HierarchyOrder(BiTreeNode* root)
{
	queue<BiTreeNode*> q;
	q.push(root);
	while( !q.empty() )
	{
		BiTreeNode* b = q.front();
		q.pop();
		printf("%c",b->data);
		if( b->left != NULL )  q.push(b->left);
		if( b->right != NULL ) q.push(b->right);
	}
}
