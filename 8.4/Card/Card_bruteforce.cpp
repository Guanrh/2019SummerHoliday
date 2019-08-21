#include <cstdio>
#include <algorithm>

using namespace std;

int x[110000],n,m,ya[110000],yd[110000],na,nd,bz[110000];
long long ans2,ans3,ans;
char c1,c2,c3;

void sol1()
{
	int l=m,r=1;
	while (l && r<=na)
	{
		if (x[l]<ya[r]) break;
		ans+=x[l]-ya[r];
		l--;
		r++;
	}
	while (l && r>na && nd==0)
	{
		ans+=x[l];
		l--;
	}
	//printf("%d\n",ans);
}

void sol2()
{
	int l=1,r=1;
	while (r<=nd && l<=m)
	{
		if (x[l]>yd[r]) r++,bz[l]=1;
		l++;
	}
	if (l>m)
		return;

	l=m,r=1;
	int ff=1;
	while (l && r<=na)
	if (bz[l]) l--;
	else
	{
		if (x[l]<ya[r])
		{
			break;
		}
		ans2+=x[l]-ya[r];
		bz[l]=1;
		l--;
		r++;
	}
	if (r>na)
		for (int i=1;i<=m;i++) if (bz[i]==0) ans2+=x[i];
}

int main()
{
	//freopen("card11.in","r",stdin);
	int tmp;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) 
	{
		c1=getchar();
		while (!(c1>='A' && c1<='Z')) c1=getchar();
		c2=getchar();
		c3=getchar();
		scanf("%d",&tmp);
		if (c1=='D') yd[++nd]=tmp;
		else ya[++na]=tmp;
	}
	for (int i=1;i<=m;i++) scanf("%d",&x[i]);
	sort(x+1,x+1+m);
	sort(yd+1,yd+1+nd);
	sort(ya+1,ya+1+na);


	sol1();

	sol2();

	if (ans2>ans) ans=ans2;

	printf("%lld\n",ans);

}
