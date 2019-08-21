//本代码默认1为源点，n为汇点
#include<bits/stdc++.h>
#define N 1100

using namespace std;

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

int W[N][N]/*W[i][j]表示从i到j的最大流量*/,pre[N]/*pre[i]表示该增广路中从哪个节点走到i节点*/,vis[N]/*bfs标志数组*/,n,m;
int q[1100000];//找增广路时的队列

int CanFindPath()
{
	memset(pre,0,sizeof pre);
	memset(vis,0,sizeof vis);
	pre[1] = 0;
	vis[1] = 1;

	memset(q,0,sizeof q);
	q[1] = 1;/*从源点开始走*/
	int head = 0 , tail = 1;

	int flag = 0;/*是否找到增广路*/

	while (head<tail)
	{
		++head;
		int now = q[head];/*当前走到的节点*/

		for (int i = 1;i <= n;i ++)/*枚举这条边的终点*/
			if ( W[now][i] > 0 && !vis[i] )/*该条边剩余容量大于0 且 点i未访问过*/
			{
				pre[i] = now;/*记录路径*/
				vis[i] = 1;
				if ( i == n )/*到达终点*/
				{
					flag = 1;
					tail = -1;/*结束bfs*/
					break;
				}
				else
					q[++tail] = i;
			}
	}

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
		scanf("%d%d%d",&u,&v,&w);//从u到v的容量为w
		W[u][v] += w;//因为会重边，所以要累加
	}

	int MaxFlow = 0;/*最大流*/
	int aug = 0;/*记录每条增广路的流量*/

	while ( aug = Augment() ) /*还能找到增广路*/
		MaxFlow += aug; /*累加该条增广路的流量*/

	printf("%d\n",MaxFlow);
}
