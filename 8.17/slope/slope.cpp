#include <cstdio>
#include <algorithm>

using namespace std;

int P,Q,wz,n,xx,yy;
double ans;

double abss(double x){return x<0?-x:x;}

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); }

struct node
{
	long long x,y,xx,yy;
}a[210000];

int cmp(node a,node b)
{
	return a.y<b.y;
}

double pd(int y1,int x1,int y2,int x2)
{
	return (double)(y1*1.0/x1-y2*1.0/x2);
}

int main()
{
	freopen("slope.in","r",stdin);
	freopen("slope.out","w",stdout);
	scanf("%d%d%d",&n,&P,&Q);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i].xx,&a[i].yy),a[i].y = a[i].yy * Q - a[i].xx * P,a[i].x = a[i].xx * Q;
	sort(a+1,a+1+n,cmp);

	ans=9999999;
	int xx,yy;
	for (int i=1;i<n;i++)
	{
		double val=pd(P,Q,a[i].yy-a[i+1].yy,a[i].xx-a[i+1].xx);
		if (abss(val)==abss(ans) && val<ans)
			{
				ans=val;
				yy=a[i].yy-a[i+1].yy;
				xx=a[i].xx-a[i+1].xx;
			}
			if (abss(val)<abss(ans))
			{
				ans=val;
				yy=a[i].yy-a[i+1].yy;
				xx=a[i].xx-a[i+1].xx;
			}
	}

	int tmp=gcd(xx,yy);
	if (tmp<0) tmp=-tmp;
	if (xx<=0 && yy<=0) tmp=-tmp; 
	printf("%d/%d\n",yy/tmp,xx/tmp);
}