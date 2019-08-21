#pragma GCC optimize(3)
#pragma G++ optimize(3)
#include <cstdio>
#define db double

using namespace std;

db f[2][(1<<20)+10],p[22][22];
int n;

db max(db x,db y){return x>y?x:y;}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%lf",&p[i][j]),p[i][j]=p[i][j]*1.0/100.0;

	f[0][0]=100.0;
	for (register int i=1;i<=n;i++)
		for (register int s=0;s<(1<<n);s++)
			for (register int j=1;j<=n;j++)
				if(!(s&(1<<j-1)))
					f[i%2][s|1<<(j-1)]=max((db)f[i%2][s|1<<(j-1)],(db)f[(i-1)%2][s]*1.0*p[i][j]);
	printf("%.6lf\n",f[n%2][(1<<n)-1]);
}