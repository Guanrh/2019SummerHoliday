#include<cstdio>

using namespace std;

int n,k,num,tx[1100],ty[1100],x[1100],y[1100],delta_x,delta_y;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d%d%d",&num,&tx[i],&ty[i]);
		x[i]=(num-1)/n+1;
		y[i]=(num-1)%n+1;
	}

	for (int i=1;i<=k;i++)
	{
		delta_x=x[i]<=tx[i]?tx[i]-x[i]:n-x[i]+tx[i];
		delta_y=y[i]<=ty[i]?ty[i]-y[i]:n-y[i]+ty[i];
		printf("%d\n",delta_x+delta_y);

		for (int j=i+1;j<=k;j++)
			if (x[j]==x[i]) y[j]=(y[j]+delta_y-1)%n+1;

		for (int j=i+1;j<=k;j++)
			if (y[j]==ty[i]) x[j]=(x[j]+delta_x-1)%n+1;
	}
}