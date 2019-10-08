#include<bits/stdc++.h>

using namespace std;

const int Inf = 99999999;

struct List{
	List *nxt;
	int a,b;   //  ax^b
}c1,c2,ans; 

int n,m;
int a,b;

void Init(){
	cin>>n>>m;
	List *tmp;
	tmp = &c1;
	for(int i=1;i<=n;i++)
	{
		List *cnt = new List;
		scanf("%d %d",&a,&b);
		if(i == 1)
		{
			c1.a = a;
			c1.b = b;
			c1.nxt = NULL;
			continue; 
		}
		cnt->a = a,cnt->b = b;
		cnt->nxt = NULL;
		tmp->nxt = cnt;
		tmp = tmp->nxt;
	}
	tmp = &c2;
	for(int i=1;i<=m;i++)
	{
		List *cnt = new List;
		scanf("%d %d",&a,&b);
		if(i == 1)
		{
			c2.a = a;
			c2.b = b;
			c2.nxt = NULL;
			continue; 
		}
		cnt->a = a,cnt->b = b;
		cnt->nxt = NULL;
		tmp->nxt = cnt;
		tmp = tmp->nxt;
	}
}

List Sort(List c,int size){
	List tmp;
	List *cnt = &tmp;
	tmp.nxt = NULL;
	tmp.b = -1;
	while( size -- )
	{
		int Max = -Inf;
		List *pos = &c;
		for(List *j = &c;j!=NULL;j=j->nxt)
			if( j->b > Max )
			{
				Max = j->b;
				pos = j;
			}
		if( tmp.b == -1 )
			tmp.a = pos->a,tmp.b = pos->b;
		else 
		{
			List *Add = new List;
			Add->a = pos->a;
			Add->b = pos->b;
			Add->nxt = NULL;
			cnt->nxt = Add;
			cnt = cnt->nxt;
		}
		if( size == 0 )
			break;
		if( c.b == Max )
		{
			c=*(c.nxt);
			continue;
		}
		for(List *j = &c;j->nxt!=NULL;j=j->nxt)
			if( (j->nxt)->b == Max )
			{
				j->nxt = j->nxt->nxt;
				break;
			} 
	}
//	for(List *i = &tmp;i!=NULL;i=i->nxt)
//		cout<<i->a<<" "<<i->b<<endl;
	return tmp;
}

void Work(){
	bool flag = true;
	List *cnt = &ans,*a1 = &c1,*a2 = &c2;
	while( a1 != NULL && a2 != NULL )
	{
		List *Add = new List;
		if( a1->b == a2->b )
		{
			int tmp = a1->a + a2->a;
			Add->a = a1->a + a2->a;
			Add->b = a1->b;
			Add->nxt = NULL;
			a1 = a1->nxt;
			a2 = a2->nxt;
			if( tmp == 0 )	continue;
		}
		else if( a1->b > a2->b )
		{
			int tmp = a1->a;
			Add->a = tmp;
			Add->b = a1->b;
			Add->nxt = NULL;
			a1 = a1->nxt;
			if( tmp == 0 )	continue;
		}
		else 
		{
			int tmp = a2->a;
			Add->a = a2->a;
			Add->b = a2->b;
			Add->nxt = NULL;
			a2 = a2->nxt;
			if( tmp == 0 )	continue;
		}
		if( flag )  cnt->a = Add->a,cnt->b = Add->b,cnt->nxt = NULL;
		else cnt->nxt = Add,cnt = cnt->nxt;
		flag = false;
	}
	if( a1 == NULL )  cnt->nxt = a2;
	else if( a2 == NULL )  cnt->nxt = a1;
}

int main(){
	Init();
	c1 = Sort(c1,n);
	c2 = Sort(c2,m);
	cout<<endl;
	Work();
	for(List *i = &ans;i!=NULL;i=i->nxt)
	cout<<i->a<<" "<<i->b<<endl;
	return 0;
}

/*
5 6

2 3
3 2
4 5
1 1
5 4

1 2
5 6
2 3
4 5
3 4
1 7
*/

