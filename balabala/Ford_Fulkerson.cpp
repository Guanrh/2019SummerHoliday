//本代码默认1为源点，n为汇点
#include<bits/stdc++.h>
#define N 1100

using namespace std;

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

int W[N][N]/*W[i][j]表示从i到j的最大流量*/,pre[N]/*pre[i]表示该增广路中从哪个节点走到i节点*/,vis[N]/*dfs标志数组*/,n,m,flag;

void dfs(int now)
{
	if (now == n)
	{
		flag = 1;/*找到增广路*/
		return;
	}
	for (int i = 1;i <= n;i ++)/*枚举这条边的终点*/
		if ( W[now][i] > 0 && !vis[i] )/*要有剩余容量且终点未访问过才能走*/
		{
			pre[i] = now;/*记录路径*/
			vis[i] = 1;
			dfs(i);
			vis[i] = 0;
		}
}

int CanFindPath()
{
	memset(pre,0,sizeof pre);
	memset(vis,0,sizeof vis);
	pre[1] = 0;
	vis[1] = 1;

	flag = 0;/*是否找到增广路*/

	dfs(1);	/*寻找增广路，从源点1开始走*/

	return flag;
}

int Augment()
{
	if ( CanFindPath() )/*如果能找到增广路就统计流量*/
	{
		int MinFlow = 1<<29; /*记录该条增广路上流量最小的一条边*/

		int now = n;
		while ( pre[now] ) /*回溯路径*/
		{
			MinFlow = min( MinFlow,W[pre[now]][now] );
			now = pre[now];
		}

		now = n;
		while ( pre[now] )/*建立反向边*/
		{
			W[pre[now]][now] -= MinFlow;/*减去已经流去的流量*/
			W[now][pre[now]] += MinFlow;/*由 f(i,j) = -f(j,i)的性质*/
			now = pre[now];
		}

		return MinFlow;
	}

	return 0;//如果找不到增广路就返回 0 流量
}

int main()
{
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);//n个点，m条边
	for (int i = 1;i <= m;i ++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);//从u到v的流量为w
		W[u][v] += w;//因为会重边，所以要累加
	}

	int MaxFlow = 0;/*最大流*/
	int aug = 0;/*记录每条增广路的流量*/

	while ( aug = Augment() ) /*还能找到增广路*/
		MaxFlow += aug; /*累加该条增广路的流量*/

	printf("%d\n",MaxFlow);
}
