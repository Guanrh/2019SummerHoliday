#include <cstdio>
#include <cstring>

using namespace std;

char s[20][20];
int n,m,r,c,ans,a[40][40],tmp[40][40],have[20],f[20];

int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}

void dg(int t,int s)
{
	if (t>n)
	{
		for (int i=1;i<=m;i++) have[i]=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				have[j]|=a[i][j];

		f[0]=0;
		for (int i=1;i<=m;i++)
			f[i]=have[i]?f[max(0,i-c)]+1:min(f[i-c]+1,f[i-1]);
		ans=min(ans,f[m]+s);
		return;
	}
	dg(t+1,s);
	for (int i=t;i<=t+r-1;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=0;
	dg(t+r,s+1);
	for (int i=t;i<=t+r-1;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=tmp[i][j];
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) 
	{
		scanf("%s",s[i]+1);
		for (int j=1;j<=m;j++) a[i][j]=(s[i][j]=='X');
	}
	scanf("%d%d",&r,&c);

	ans=9999999;
	memcpy(tmp,a,sizeof a);
	dg(1,0);
	printf("%d\n",ans);
}
