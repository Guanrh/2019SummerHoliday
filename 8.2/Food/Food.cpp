#include<bits/stdc++.h>

using namespace std;

int n,s[20],b[20],mn;

int abss(int x){return x>0?x:-x;}

int min(int x,int y){return x<y?x:y;}

void dg(int t,int S,int B,int cnt)
{
	if (cnt>=1) mn=min(mn,abs(S-B));
	if (t>n) return;
	dg(t+1,S,B,cnt);
	dg(t+1,S*s[t],B+b[t],cnt+1);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&s[i],&b[i]);
	mn=1000000000;
	dg(1,1,0,0);
	printf("%d\n",mn);
}