//#include<bits/stdc++.h>

#include<cstdio>
#include<cstring>

using namespace std;

int r,c,h[110][110],x,y;
double fx[5]={0,-1,1,0,0},fy[5]={0,0,0,-1,1};
double v,f[1100][1100];
double e[52];
struct node
{
	int x,y;
	double v;
}d[1100000];

double w(int x)
{
	if (x>=0) return e[x];
	else return 1.0/e[-x];
}

int main()
{
	/**
	scanf("%lf%d%d",&v,&r,&c);
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++)
			scanf("%d",&h[i][j]);
			
	
	e[0]=1;
	for (int i=1;i<=50;i++) e[i]=e[i-1]*2;
	memset(f,127,sizeof f);
	f[1][1]=0;
	d[1].x=1;
	d[1].y=1;
	d[1].v=v;
	int head=0,tail=1;
	while (head!=tail)
	{
		for (int l=1;l<=4;l++)
		{
			x=d[head].x+fx[l];
			y=d[head].y+fy[l];
			if (x<1 || y<1 || x>r || y>c) continue;
			
			//double tmp=f[1,1];
			
			if (f[d[head].x,d[head].y]+(1.0/d[head].v)<f[x][y])
			{
				f[x][y]=f[d[head].x,d[head].y]+1.0/d[head].v;
				tail++;
				d[tail].x=x;
				d[tail].y=y;
				d[tail].v=d[head].v*1.0*w((int)h[d[head].x,d[head].y]-h[x][y]);
			}
		}
	}
	**/
	
}
