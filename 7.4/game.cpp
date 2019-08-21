#include<bits/stdc++.h>
#define ll long long

using namespace std;

int l1,l2;
ll f[2100][2100],a[2100],b[2100];

ll min(ll x,ll y){return x<y?x:y;}

int main()
{
	scanf("%d%d",&l1,&l2);
	for (int i=1;i<=l1;i++)	scanf("%lld",&a[l1-i+1]),a[l1-i+1]--;
	for (int i=1;i<=l2;i++) scanf("%lld",&b[l2-i+1]),b[l2-i+1]--;
	memset(f,127,sizeof f);
	f[0][0]=0;
	for (int i=1;i<=l1;i++)
		for (int j=1;j<=l2;j++)	
			f[i][j]=min(f[i-1][j-1],min(f[i][j-1],f[i-1][j]))+a[i]*b[j];
	printf("%lld\n",f[l1][l2]);
	return 0;
} 
