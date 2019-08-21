#include<bits/stdc++.h>
#define INF 2100000000;

using namespace std;

struct q
{
	int h,f;
}tmp[5];

int h[110][110],vis[110][110],que[110][110][5];
double t[110][110];
long long e[55];
int fx[5]={0,-1,1,0,0},fy[5]={0,0,0,-1,1};
int r,c,V,cnt;

void dfs(int x,int y,double v)
{
	//return;
	for (int i=1;i<=4;i++)
	{
		if (que[x][y][i]==999) return;
		int xx=x+fx[que[x][y][i]],yy=y+fy[que[x][y][i]];
		if (xx>r || xx<1 || yy>c || yy<1) continue;
		double vv=0;
		if (h[x][y]>h[xx][yy]) vv=v*1.0*e[h[x][y]-h[xx][yy]];
		else vv=v*1.0/e[h[xx][yy]-h[x][y]];
		if (t[x][y]+(1/v*1.0)<t[xx][yy]) 
		{
			//printf("from (%d,%d) to (%d,%d):%.3lf -> %.3lf\n",x,y,xx,yy,t[xx][yy],t[x][y]+(1/v*1.0));
			t[xx][yy]=t[x][y]+(1/v*1.0),dfs(xx,yy,vv);
		}
	}
}

int cmp(q a,q b){return a.h<b.h;}

void doit()
{
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++)
		{
			int tot=0;
			tmp[1].f=tmp[2].f=tmp[3].f=tmp[4].f=999;
			for (int f=1;f<=4;f++)
			{
				int xx=i+fx[f],yy=j+fy[f];
				if (xx>r || xx<1 || yy>c || yy<1) continue;
				tmp[++tot].h=h[xx][yy]-h[i][j],tmp[tot].f=f;
			}	
			sort(tmp+1,tmp+1+tot,cmp);
			que[i][j][1]=tmp[1].f;
			que[i][j][2]=tmp[2].f;
			que[i][j][3]=tmp[3].f;
			que[i][j][4]=tmp[4].f;
		}
}

int main()
{
	freopen("cowski.in","r",stdin);
	freopen("cowski.out","w",stdout);
	e[0]=1;
	for (int i=1;i<=51;i++) e[i]=e[i-1]*2;
	scanf("%d%d%d",&V,&r,&c);
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++)
			scanf("%d",&h[i][j]),t[i][j]=INF;
	doit();
	t[1][1]=0;
	dfs(1,1,V);
	printf("%.2lf\n",t[r][c]);
	return 0;
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++)
			printf("(%d,%d) : %d %d %d %d\n",i,j,que[i][j][1],que[i][j][2],que[i][j][3],que[i][j][4]);
}
