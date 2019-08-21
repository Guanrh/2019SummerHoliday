#include <bits/stdc++.h>

using namespace std;

int n,m,ans,a[16][16];

struct man
{
	int x,y;
}f[16];

void dg(int x,int y,int cnt)
{
	if (cnt==m) {
		ans++;
		return;
		printf("Case : %d\n",ans);
		for (int i=1;i<=m;i++) printf("%d %d\n",f[i].x,f[i].y);
		printf("\n");
	}
	if (y>n) y=1,x++;
	if (x>n)return;
	if (a[x][y])
	{
		int tmp[16][16];
		memcpy(tmp,a,sizeof a);
		int xx=x,yy=y;
		while (xx&&yy) a[xx][yy]=0,xx--,yy--;//left-up
		xx=x,yy=y;
		while (xx<=n&&yy) a[xx][yy]=0,xx++,yy--;//left-down
		xx=x,yy=y;
		while (xx&&yy<=n) a[xx][yy]=0,xx--,yy++;//right-up
		xx=x,yy=y;
		while (xx<=n&&yy<=n) a[xx][yy]=0,xx++,yy++;//right-down
		f[cnt+1]=(man){x,y};
		dg(x,y+1,cnt+1);
		memcpy(a,tmp,sizeof a);
	}
	dg(x,y+1,cnt);
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(a,true,sizeof a);
	scanf("%d%d",&n,&m);
	dg(1,1,0);
	printf("%d\n",ans);
}
