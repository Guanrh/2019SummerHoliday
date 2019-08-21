#include<bits/stdc++.h>
#define mo 10000

using namespace std;

int T,x,y,f[1100000];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&x,&y);
		f[1]=f[2]=1;
		for (int i=3;i<=y;i++) f[i]=(f[i-1]+f[i-2])%mo;
		int ans=0;
		for (int i=x;i<=y;i++) ans=(ans+f[i])%mo;
		printf("%d\n",ans);
	}
}