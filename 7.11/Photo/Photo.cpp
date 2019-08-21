#include<bits/stdc++.h>

using namespace std;

int l[200010],r[200010],f[200010],a,b,n,que[200010],head;

int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		r[b]=min(r[b],a-1);
		l[b+1]=max(l[b+1],a);
	}

	for (int i=n;i>=1;i--) r[i]=min(r[i],r[i+1]);
	for (int i=1;1<=n+1;i++) l[i]=max(l[i],l[i-1]);

	for (int i=1;i<=n+1;i++)
	{

	}
}