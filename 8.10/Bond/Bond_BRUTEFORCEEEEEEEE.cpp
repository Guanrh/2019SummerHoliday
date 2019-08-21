#include <cstdio>
#define db double

using namespace std;

int n;
db p[22][22],tmp,bz[22],ans;

db max(db x,db y){return x>y?x:y;}

void dg(int x,db P)
{
	if (x>n)
	{
		ans=max(ans,P);
		return;
	}
	for (int i=1;i<=n;i++)
		if (!bz[i])
		{
			bz[i]=1;
			dg(x+1,P*1.0*p[x][i]);
			bz[i]=0;
		}
}

int main()
{
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%lf",&tmp),p[i][j]=(db)1.0*tmp/100.0;
	dg(1,1);
	ans*=100.0;
	printf("%.6lf",ans);
	return 0;
}
