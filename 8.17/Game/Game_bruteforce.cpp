#include <cstdio>

using namespace std;

int n,ans;

void dg(int t,char fx)
{
	if (t>n)
	{
		ans++;
		return;
	}
	dg(t+1,'N');
	if (fx!='E') dg(t+1,'W');
	if (fx!='W') dg(t+1,'E');
}

int main()
{
	for (int i=1;i<=20;i++)
	{
		n=i;//scanf("%d",&n);
		ans=0;
		dg(1,'N');
		printf("Case %d:%d\n",i,ans);
	}
}