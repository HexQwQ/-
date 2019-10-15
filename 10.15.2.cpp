bool LL_InsAfter(LinkList* llist, T x)
{
	
	if( llist->curr == NULL )  
	{
		llist->front = new LinkNode;
		llist->front->data = x;
		llist->front->next = NULL;
		llist->curr = llist->front;
		llist->len++;
		return true;
	}
	LinkNode *a = new LinkNode;
	a->data = x;
	a->next = llist->curr->next;
	llist->curr->next = a;
	llist->curr = llist->curr->next;
	llist->len++;
}
