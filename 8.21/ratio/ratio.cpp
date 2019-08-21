#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct EDGE
{
	int u,v,w;
}e[1000];

int a[20],w[30][30],n,m,ANS[20],fa[20],now[20],tot,sum1,sum2,tmp;

double ans;

int cmp(EDGE a,EDGE b){return a.w<b.w;}

int father(int x)
{
	if (fa[x]!=x) fa[x]=father(fa[x]);
	return fa[x];
}

void check()
{
	tot=sum1=sum2=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++) sum2+=a[now[i]];
	for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++)
			e[++tot]=(EDGE){now[i],now[j],w[now[i]][now[j]]};

	sort(e+1,e+1+tot,cmp);

	int F1,F2;
	for (int i=1;i<=tot;i++)
	{
		F1=father(e[i].u);F2=father(e[i].v);
		if (F1==F2) continue;
		fa[F1]=F2;
		sum1+=e[i].w;
	}

	if ((double)sum1*1.0/sum2<ans) 
	{
		ans=(double)sum1*1.0/sum2;
		memcpy(ANS,now,sizeof now);
	}
}

void dg(int t,int cnt)
{
	if (cnt==m)
	{
		//printf("!%d\n",++tmp);
		check();
		return;
	}
	if (t>n) return;
	now[cnt+1]=t;
	dg(t+1,cnt+1);
	dg(t+1,cnt);
}

int main()
{
	//freopen("ratio.in","r",stdin);
	//freopen("ratio.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&w[i][j]);

	ans=999999999;
	dg(1,0);
	printf("%.9lf\n",ans);
	for (int i=1;i<=m;i++)
		printf("%d ",ANS[i]);
}
