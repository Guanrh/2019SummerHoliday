#include <cstdio>

using namespace std;

int n,m,ans;

int abss(int x){return x>0?x:-x;}

void dg(int t,int s,int x)
{
	if (t==0) x=0;
	if (x>=m) return;
	if (s==n)
	{
		if (t==0)ans++;
		return;
	}
	if (abss(t)>n-s) return;
	dg(t+1,s+1,x+1);
	dg(t-1,s+1,x+1);
}

int main()
{
	scanf("%d%d",&n,&m);
	/*for (int i=1;i<=12;i++)
		for (int j=1;j<=16;j++)
		{	
			n=i,m=j,ans=0;
			dg(0,0,0);
			printf("Case %d %d:%d\n",i,j,ans);
		}
	n=10,m=6;*/
	ans=0;
	dg(0,0,0);
	printf("%d\n",ans);
}