int Graph_WidthFirst(Graph*g, int start, Edge* tree)
//从start号顶点出发宽度优先遍历，（编号从0开始）
//返回访问到的顶点数，
//tree[]输出遍历树
//返回的tree[0]是(-1, start), 
//真正的遍历树保存在tree[1..return-1], return是返回值
//顶点的访问次序依次为tree[0].to, tree[1].to,  ..., tree[return-1].to
//输入时，tree[]的长度至少为顶点数
//返回值是从start出发访问到的顶点数
{
	const int MAX=1000;
	Edge queue[MAX];
	int head=0, tail=0;
#define In__(a,b)  {queue[tail].from=a; queue[tail].to=b; tail=(tail+1)%MAX;}/////////
#define Out__(a,b)  {a=queue[head].from; b=queue[head].to; head=(head+1)%MAX;}//
#define QueueNotEmpty (head!=tail?1:0)///////////////////////////////////
#define HasEdge(i,j)  (g->adj[(i)*g->n+(j)]==1)

	char* visited=(char*)malloc(sizeof(char)*g->n);
	memset(visited, 0, sizeof(char)*g->n);

	int parent=-1;  
	int curr=start;
	In__(parent, curr); 
	int k=0; //已经访问的结点数
	/*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
	tree[k].from = parent;
	tree[k++].to = curr;
	bool vis[2333] = {false};
	vis[curr] = true;
    while(QueueNotEmpty)
	{
		int a,b;
		Out__(a,b);
		for(int i=0;i<g->n;i++)
		{
			if( vis[i] )  continue;
			if( !HasEdge(b,i) )  continue;
			In__(b,i);
			tree[k].from = b;
			tree[k++].to = i;
			vis[i] = true;
		}
	}
    /*****END*******/
	return k;
#undef In__//////////////////////////////
#undef Out__///////////////////////////////
#undef QueueNotEmpty////////////////////////
#undef HasEdge
}
