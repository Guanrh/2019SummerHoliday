#include <bits/stdc++.h>

using namespace std;

int n,m,a[60],can[60],ans,tmp[60],tot;

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); }
int lcm(int a,int b){return (a*b/gcd(a,b));}

int main()
{
	freopen("running.in","r",stdin);
	freopen("running.out","w",stdout);
	memset(can,1,sizeof can);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]),a[i]=gcd(a[i],n);
	sort(a+1,a+1+m);
	tot=0;
	for (int i=1;i<=m;i++) 
	{
		++tot;int tmp=a[i];
		while (a[i+1]==tmp) i++;
		a[tot]=tmp;
	}
	m=tot;
	for (int i=1;i<=m;i++)
			for (int j=1;j<=m-1;j++)
				for (int k=j+1;k<=m;k++)
						if (a[i]%lcm(a[j],a[k])==0) can[i]=0;
	for (int i=1;i<=m;i++) 
		if (can[i])
			ans+=n/a[i];
	for (int i=1;i<=m-1;i++)
		for (int j=i+1;j<=m;j++)
			if (can[i]&&can[j])
			ans-=n/lcm(a[i],a[j]); 
	int cnt=0;
	for (int i=1;i<=m;i++) if (can[i])cnt++;
	printf("%d\n",n-ans-cnt+1);
}
