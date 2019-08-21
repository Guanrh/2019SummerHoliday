#include <cstdio>

using namespace std;

int ans,n,m,bz[20];

void dg(int t,int cnt)
{	
	if (cnt>=m)
	{
		ans++;
		return;
	}
	if (t>n) return;
	dg(t+1,cnt+1);
	dg(t+1,cnt);
}

int main()
{
	scanf("%d%d",&n,&m);
	dg(1,0);
	printf("%d\n",ans);
}