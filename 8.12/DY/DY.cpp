#include <cstdio>
#define N 310

using namespace std;

int a[N][N],w[N][N],n,m,e,l,p,K;
int d

int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}

void spfa()

int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&e,&l,&p,&K);
	for (int i=1;i<=e;i++)
	{
		int u,v,W;scanf("%d%d%d",&u,&v,&W);
		w[u][v]=w[v][u]=min(w[v][u],W);
	}
	for (int i=1;i<=n;i++) a[i][i-1]=min(a[i][i-1],0),a[i-1][i]=min(a[i-1][i],1);
	for (int i=1;i<=p;i++)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		a[v][u-1]=min(a[v][u-1],-w);
	}
	/*slove();
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				*/

	spfa();
}