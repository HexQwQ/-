bool SL_InsAt(SeqList* slist, int i, T x)
{
	for (int j=slist->len;j>=i+1;j--)
		slist->data[j]=slist->data[j-1];
	slist->data[i]=x;
	slist->len++;
	return true;
}

T SL_DelAt(SeqList* slist, int i)
{
	int k = slist->data[i];
	for (int j=i;j<slist->len-1;j++) 
		slist->data[j] = slist->data[j+1];
	slist->len--;
    return k;
}

int SL_DelValue(SeqList* slist, T x)
{
    int j;
	bool flag = false;
	for(j=0;j<slist->len;j++)
		if( x == slist->data[j] ) 
		{
			flag = true;
			break;
		}
	if( flag == false )  return -1;
	int k = j;
	SL_DelAt(slist,j);
	return k;
}
