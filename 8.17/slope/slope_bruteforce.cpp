#include <cstdio>

using namespace std;

int P,Q,x[1100],y[1100],wz,n,xx,yy;
double ans;

double abss(double x){return x<0?-x:x;}

double pd(int y1,int x1,int y2,int x2)
{
	return (double)(y1*1.0/x1-y2*1.0/x2);
}

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); }

int main()
{
	freopen("slope.in","r",stdin);
	freopen("slope.out","w",stdout);
	scanf("%d%d%d",&n,&P,&Q);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	ans=999999999;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			double val=pd(P,Q,y[i]-y[j],x[i]-x[j]);
			if (abss(val)==abss(ans) && val<ans)
			{
				ans=val;
				yy=y[i]-y[j];
				xx=x[i]-x[j];
			}
			if (abss(val)<abss(ans))
			{
				ans=val;
				yy=y[i]-y[j];
				xx=x[i]-x[j];
			}
		}
	int tmp=gcd(xx,yy);
	if (tmp<0) tmp=-tmp;
	if (xx<=0 && yy<=0) tmp=-tmp; 
	printf("%d/%d\n",yy/tmp,xx/tmp);
}