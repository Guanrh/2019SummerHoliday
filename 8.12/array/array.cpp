#include <cstdio>
#include <cstring>

using namespace std;

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

struct node
{
	int p,n;
}x[110000];

int n,f[110000],a[410000],low,pre[110000],bz[110000],head,tail,q[110000];

int i;

void PushUp(int rt){a[rt]=max(a[rt<<1],a[rt<<1|1]);}

void Build(int l,int r,int rt)
{
	if (l==r)
	{
		a[rt]=x[l].n;
		return;
	}
	int mid=(l+r)>>1;
	Build(l,mid,rt<<1);
	Build(mid+1,r,rt<<1|1);
	PushUp(rt);
}

int Query(int L,int R,int l,int r,int rt)
{
	if (L<=l && R>=r) return a[rt];
	int mid=(l+r)>>1,ANS=0;
	if (L<=mid) ANS=max(ANS,Query(L,R,l,mid,rt<<1));
	if (R>mid) ANS=max(ANS,Query(L,R,mid+1,r,rt<<1|1));
	return ANS;
}

void predo()
{
	memset(bz,0,sizeof bz);
	for (i=1;i<=n;i++) pre[i]=-1;
	for (i=1;i<=n;i++)
	{
		if (bz[x[i].p]) pre[i]=bz[x[i].p];
		bz[x[i].p]=i;
	}
}

int slope(int x,int y)
{
	return f[x]-f[y]+Query(x,i,1,n,1)-Query(y,i,1,n,1);
}

int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d%d",&x[i].p,&x[i].n);
	predo();
	Build(1,n,1);

	low=0;
	memset(f,127,sizeof f);
	f[0]=0;
	head=1;
	tail=1;

	for (i=1;i<=n;i++)
	{
		low=max(low,pre[i]);
		/*for (int j=low;j<=i;j++)
			f[i]=min(f[i],f[j-1]+Query(j,i,1,n,1));*/
		while (head<tail && slope(q[head],q[head+1])>=0) head++;
		while (head<tail && q[head]<low) head++;
		q[++tail]=i;
		while (head<tail && slope(q[tail-1],q[tail])>=slope(q[tail],i)) tail--;
		f[i]=f[q[head]]+Query(q[head]+1,i,1,n,1);
	}
	printf("%d\n",f[n]);
}
