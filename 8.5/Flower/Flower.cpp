#include<bits/stdc++.h>
#define MAXN 110000

using namespace std;

int T[1100000],M,n,ans,m,newx,newy,last[MAXN];

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

void update(int x)
{
	int a=max(T[x*2],T[x*2+1]);
	T[x*2]-=a,T[x*2+1]-=a,T[x]+=a;
}

void add(int s,int t,int x)
{
	int A=0;
	for (s=s+M-1,t=t+M+1;s^t^1;s>>=1,t>>=1)
	{
		if (!(s&1)) T[s^1]+=x;
		if (   t&1) T[t^1]+=x;
		update(s>>1);
		update(t>>1);
	}
	for (s>>=1;s;s>>=1) update(s);
}

int Get(int x)
{
	int res=0;
	while (x)
	{
		res+=T[x];
		x/=2;
	}
	return res;
}

int main()
{	
	//freopen("test1.in","r",stdin);
	for (M=1;M<=MAXN;M<<=1);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		newx=Get(M+x),newy=Get(M+y);
		printf("%d\n",newx-last[x]+newy-last[y]);
		add(x+1,y-1,1);
		last[x]=newx;
		last[y]=newy;
	}
}
