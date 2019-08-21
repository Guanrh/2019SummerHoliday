//#pragma G++ optimize(3)
//#pragma GCC optimize(3)
#include <cstdio>

using namespace std;

int n,p[25][25];
double f[22][(1<<21)+10];

double max(double x,double y){return x>y?x:y;}

int main()
{
	freopen("test.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&p[i][j]);
	for (int i=0;i<1<<n;i++) f[i][0]=1;
	for (int s=0;s<1<<n;s++)
		for (int i=1;i<=n;i++)
			if (!s&(1<<(i-1)))
				for (int j=1;j<=n;j++)
					f[j][s|(1<<i-1)]=max(f[j][s|(1<<i-1)],f[j][s]*1.0*p[i][j]/100.0);


	double ans=0;
	for (int i=1;i<1<<n;i++)
		ans=max(ans,f[n][i]);
	printf("%lf\n",ans);
}
