#include <bits/stdc++.h>

using namespace std;

int K,len,n,v[20][20],w[20][20],ans=1<<30,f[1<<16+10][20];
char s[51000];

int min(int x,int y){return x<y?x:y;}

int main()
{
	scanf("%d",&K);
	scanf("%s",s+1);
	len=strlen(s+1);
	n=len/k;
	for (int i=1;i<=n;i+=k)
		for (int j=1;j<=K;j++)
			for (int k=1;k<=K;k++)
				v[j][k]+=(s[i+j-1]^s[i+k-1]);
	for (int i=1;i+k<=n;i+=k)
		for (int j=1;j<=K;j++)
			for (int k=1;k<=K;k++)
				w[j][k]+=(s[i+j-1]==s[i+K+k-1]);
	for (int i=1;i<=k;i++)
	{
		memset(f,0x3f,sizeof f);
		for
	}
}
