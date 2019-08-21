#pragma GCC optimize(3)
#pragma G++ optimize(3)
#include <bits/stdc++.h>

using namespace std;
 
int T;
double x[4],y[4],len[4],mn,r,ans;

double max(double x,double y){return x>y?x:y;}
double min(double x,double y){return x<y?x:y;}
double abss(double x){return x<0?-x:x;}
double sqr(double x){return x*1.0*x;}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]);
		len[1]=sqrt(sqr(x[1]-x[2])+sqr(y[1]-y[2]));
		len[2]=sqrt(sqr(x[1]-x[3])+sqr(y[1]-y[3]));
		len[3]=sqrt(sqr(x[3]-x[2])+sqr(y[3]-y[2]));
		ans=len[1]+len[2]+len[3];
		//printf("%lf\n",r);
		int anss=(int)ans;
		printf("%d\n",anss);
	}
}
