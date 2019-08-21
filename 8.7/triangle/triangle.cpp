#include<cstdio>
#define ll long long

using namespace std;

struct node
{
	int x,y;
}a[1600];

int n,ans;

int main()
{
	//freopen("data10.in","r",stdin);
	scanf("%d",&n);
	for (register int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	printf("%d\n",ans);
}