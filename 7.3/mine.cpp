#include<bits/stdc++.h>

using namespace std;

int n,h;
double l,r,mid,ans;

double max(double x,double y){return x>y?x:y;}
double min(double x,double y){return x<y?x:y;}


int main()
{
	scanf("%d%d",&n,&h);
	double a[n+2][h+2];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=h;j++)
			scanf("%lf",&a[i][j]);
	l=0;
	r=1000000010;
	//r=110;
	while (l<=r)
	{
		mid=(l+r)*1.0/2;
		
		
		double x=mid;
		double delta=0;
		int flag=0;
		for (int i=1;i<=n;i++)
		{
			double tmp=0,mx=-1000000000;
			for (int j=1;j<=h;j++)
				tmp=tmp+a[i][j]-x,mx=max(tmp,mx);
			if (mx!=0) flag=1;
			delta+=mx;
		}
		//return (delta>=0);
		
		
		if (delta>=0 && flag)
		{
			l=mid+0.0000001;
			ans=max(ans,mid);
		}
		else r=mid-0.0000001;
	}
	printf("%.4lf",ans);
}
