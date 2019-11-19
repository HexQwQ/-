int Size = 0;//  点的个数
bool vis[2333];  //  标记 访问过的点
bool CheckEdge(Graph* g,int i,int j){
	return g->adj[i*g->n+j] == 1;
}
void dfs(int now,Graph* g,Edge* tree){   //  憨批才会手写栈
	for(int i=0;i<g->n;i++)
	{
		if( vis[i] )  continue;
		if( !CheckEdge(g,now,i) )  continue;
		vis[i] = true;
		tree[Size].from = now;
		tree[Size++].to = i;
		dfs(i,g,tree);
	}
	return ;
}

int Graph_DepthFirst(Graph*g, int start, Edge* tree)
//从start号顶点出发深度优先遍历，（编号从开始）
//返回访问到的顶点数，
//tree[]输出遍历树
//返回的tree[0]是(-1, start), 
//真正的遍历树保存在tree[1..return-1], return是返回值
//顶点的访问次序依次为tree[0].to, tree[1].to, ..., tree[return-1].to
//输入时，tree[]的长度至少为顶点数
//返回值是从start出发访问到的顶点数
{
	/*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
    vis[start] = true;
	tree[Size].from = -1;
	tree[Size++].to = start;
	dfs(start,g,tree);
	return Size;
    /*****END*******/
}
