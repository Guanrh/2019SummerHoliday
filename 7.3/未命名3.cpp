#include<bits/stdc++.h>
#define N 100010
#define open(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define mem(a,b) memset(a,b,sizeof(a))
#define mcy(a,b) memcpy(a,b,sizeof(a))
using namespace std;

struct edge
{int v,fr;}e[N*2]; int tail[N],tot;

int l,r,mid;
int n,t,i,j,ans,q;
int id[N],fo[N],f[N][20],E[N*2][2],num[N*14],lazy[N*14],full[N*14];


void qsort(int l,int r)
{
	int i=l,j=r;
	int mid = E[(l+r)/2][1];
	while(i<j)
	{
		while(E[i][1] > mid) ++i;
		while(E[j][1] < mid) --j;
		if(i<=j)
		{
			swap(E[i][0],E[j][0]);
			swap(E[i][1],E[j][1]);
			++i,--j;
		}
	}
	if(i<r)qsort(i,r);
	if(j>l)qsort(l,j);
}

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

void dfs(int x,int fr)
{
	for(int p=tail[x];p;p=e[p].fr)
	{
		int v=  e[p].v;
		if(v!=fr)
		{
			f[v][0] = x;
			dfs(v,x);
		}
	}
	++q;
	id[q] = x;
	fo[x] = q;
	
}

void build(int k,int l,int r)
{
	if(l==r) 
	{
		full[k]=1;return ;}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	full[k] = full[k*2] + full[k*2+1];
}

void init()
{
	build(1,1,n);
	dfs(1,0);// id ,fo 
	
	// f
	for(j=1;j<20;j++) 
	 for(i=1;i<=n;i++) f[i][j] = f[f[i][j-1]][j-1] ; 
	
}

void pushdown(int k)
{
	if(lazy[k])
	{
		lazy[k]=0;
		lazy[k*2] = lazy[k*2+1] = 1;
		num[k] =full[k];
	}
}

void change(int k,int l,int r,int x,int y)
{
	pushdown(k);
	if(l==x && r==y)
	{
		lazy[k]=1;
		return ;
	}
	int mid=(l+r)/2;
	
	if(y<=mid) change(k*2,l,mid,x,y); else 
	if(x>mid) change(k*2+1,mid+1,r,x,y); else
		change(k*2,l,mid,x,mid) , change(k*2+1,mid+1,r,mid+1,y);
	pushdown(k*2); pushdown(k*2+1);
	num[k] = num[k*2] + num[k*2+1];
	
}

int find(int k,int l,int r,int x,int y)
{
	pushdown(k);
	if(l==x && r==y) return num[k];
	int mid =(l+r)/2;
	if(y<=mid) return find(k*2,l,mid,x,y); else
	if(x>mid) return find(k*2+1,mid+1,r,mid+1,y); else
	return find(k*2,l,mid,x,mid) + find(k*2+1,mid+1,r,mid+1,y);
}

int tag(int k,int l,int r,int t)
{
	pushdown(k);
	if(l==r) return num[k];
	int mid=(l+r)/2;
	if(t<=mid) return tag(k*2,l,mid,t); else return tag(k*2+1,mid+1,r,t);
}

void del(int k,int l,int r,int t)
{
	pushdown(k);
	if(l==r) 
	{
		num[k]=0;
		return ;
	}
	int mid=(l+r)/2;
	if(t<=mid)  del(k*2,l,mid,t); else del(k*2+1,mid+1,r,t);
	pushdown(k*2); pushdown(k*2+1);
	num[k] = num[k*2] + num[k*2+1];
	
}

int main()
{
	scanf("%d%d",&n,&t); 
	for(i=1;i<n;i++) scanf("%d%d",&E[i][0],&E[i][1]);
	for(i=n;i<=n*2-2;i++) E[i][0] = E[i-n+1][1] , E[i][1] = E[i-n+1][0];
	qsort(1,n*2-2); // E[][1]
	for(i=1;i<=n*2-2;i++) add(E[i][0],E[i][1]);
	
	init(); 
	
	for(i=1;i<=t;i++)
	{
		int op=0,x=0,get=0;
		scanf("%d%d",&op,&x);
		if(op == 1)
		{
			l=1;
			r=n;
			while(l<=r)
			{
				mid = (l+r)/2;
				if(mid-find(1,1,n,1,mid)>=x) 
				{
					get = mid;
					r = mid-1;
				}else l=mid + 1;
			}
			
			change(1,1,n,1,get); 
			
			printf("%d\n" , id[get]);
		}
		else
		{
			int now = x,ans=0;
			for(j=19;j>=0;j--) if(f[now][j] && tag(1,1,n,fo[f[now][j]]) == 1 ) now = f[now][j],ans+=(1<<j);
			printf("!!del %d\n",now);
			del(1,1,n,fo[now]); 
			printf("%d\n",ans);
		} 
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=19;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}
}
