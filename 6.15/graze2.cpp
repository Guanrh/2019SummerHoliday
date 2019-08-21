#include<bits/stdc++.h>

using namespace std;

int n,s,p[1510],x,f[1600][1600];

int min(int x,int y){return x<y?x:y;}
int abss(int x){return x<0?-x:x;}

int main()
{
	freopen("graze2.in","r",stdin);
	freopen("graze2.out","w",stdout);
	scanf("%d%d",&n,&s);
	int  d=(s-1)/(n-1);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	sort(p+1,p+1+n);
	memset(f,0x3f,sizeof f);
	f[1][0]=p[1]-1;
	for (int i=2;i<=n;i++)
		for (int j=0;j<=min(i-1,(s-1)%(n-1));j++)
		{	
			int T=abss(p[i]-j*(d+1)-(i-j-1)*d-1);
			f[i][j]=min(f[i-1][j]+T,f[i][j]);
			if (j) f[i][j]=min(f[i-1][j-1]+T,f[i][j]);
		}
	printf("%d\n",f[n][(s-1)%(n-1)]);
}
