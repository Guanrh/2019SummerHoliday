#include <cstdio>

using namespace std;

char s[15][15];
int n,t,ans;

void dg(int x,int sum)
{
	if (sum>t) return;
	if (x==n && sum==t)
	{
		ans=(ans+1)%2009;
		return;
	}
	for (int i=1;i<=n;i++)
		if (s[x][i]!='0')
		{
			dg(i,sum+s[x][i]-'0');
		}
}

int main()
{
	scanf("%d%d",&n,&t);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	dg(1,0);
	printf("%d\n",ans);
}