#include <cstdio>
#include <algorithm>

using namespace std;

int n,k,ans;

int max(int x,int y){return x>y?x:y;}

struct data
{
	int b,c;
}f[40];

struct node
{
	int a,b,c;
}a[40];

void dg(int t,int x,int y,int z,int cnt)
{
	if (cnt>=k)
		if (x>y && x>z) ans++;
	if (t>n) return;
	if (x+f[t].b<=y || x+f[t].c<=z) return;
	if (n-t>=k-cnt)
		dg(t+1,x,y,z,cnt);
	dg(t+1,x+a[t].a,y+a[t].b,z+a[t].c,cnt+1);
}

void predo()
{
	f[n].b=a[n].a-a[n].b,f[n].c=a[n].a-a[n].c;
	for (int i=n-1;i>=1;i--)
	{
		for (int j=i+1;j<=n;j++)
		{
			f[i].b=max(f[i].b,f[j].b);
			f[i].c=max(f[i].c,f[j].c);
		}
		if (a[i].a>a[i].b) f[i].b+=(a[i].a-a[i].b);
		if (a[i].a>a[i].c) f[i].c+=(a[i].a-a[i].c);
	}
}

int cmp(node a,node b){return a.a<b.a;}

int main()
{
	//freopen("show.in","r",stdin);
	//freopen("show.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].a);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].b);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].c);
	sort(a+1,a+1+n,cmp);
	predo();

	dg(1,0,0,0,0);
	printf("%d\n",ans);
}
