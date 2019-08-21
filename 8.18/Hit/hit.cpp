#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
	int x,typ;
}a[210000];

int n,wz;
long long cnt1,cnt2,ans;

int cmp(node a,node b){return a.x<b.x || a.x==b.x && a.typ<b.typ;}

int max(int x,int y){return x>y?x:y;}

int main()
{
	int tot=0;
	scanf("%d",&n);
	for (int  i=1;i<=n;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		cnt1+=x;
		a[++tot]=(node){x,1};
		a[++tot]=(node){y,2};
	}
	sort(a+1,a+1+n*2,cmp);

	cnt2=0;
	for (int i=1;i<=n*2;i++)
	{
		if (a[i].typ==1) cnt1-=a[i].x,cnt2++;
		if (ans<cnt1+cnt2*a[i].x) ans=cnt1+cnt2*a[i].x,wz=a[i].x;
		if (a[i].typ==2) cnt2--;
	}
	printf("%d %lld\n",wz,ans);
}