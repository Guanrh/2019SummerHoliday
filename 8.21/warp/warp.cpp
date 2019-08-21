#include <cstdio>
#include <cstring>
#include <cmath>
#define db double

using namespace std;

struct node
{
	db x,y,z,r;
}a[110];

db w[105][105],sx,sy,sz,tx,ty,tz,ans;
int n;

db sqrr(db x){return (db)x*x;}
db abss(db x){return x<0?-x:x;}

db dist(int x,int y)
{
	return (db)sqrt(sqrr(a[x].x-a[y].x)+sqrr(a[x].y-a[y].y)+sqrr(a[x].z-a[y].z));
}

db min(db x,db y){return x<y?x:y;}

int main()
{
	freopen("warp.in","r",stdin);
	freopen("warp.out","w",stdout);
	while (1)
	{
		for (int i=0;i<=102;i++)
			for (int j=0;j<=102;j++)
				w[i][j]=99999999;
		for (int i=0;i<=105;i++) a[i]=(node){0,0,0,0};
		sx=sy=sz=tx=ty=tz=0;
		int n;
		scanf("%d",&n);
		if (n==-1) return 0;
		for (int i=1;i<=n;i++) scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
		n++;
		scanf("%lf%lf%lf%lf%lf%lf",&a[0].x,&a[0].y,&a[0].z,&a[n].x,&a[n].y,&a[n].z);

		for (int i=0;i<=n;i++)
			for (int j=i+1;j<=n;j++)
			{
				w[i][j]=w[j][i]=(dist(i,j)-a[i].r-a[j].r)*10.0;
				if (w[i][j]<0) w[i][j]=w[j][i]=0;
			}

		for (int k=0;k<=n;k++)
			for (int i=0;i<=n;i++)
				for (int j=0;j<=n;j++)
					w[i][j]=min(w[i][j],w[i][k]+w[k][j]);

		db anss=w[0][n];
		int ans=round(anss);
		printf("%d\n",ans);
	}
}
