#include<bits/stdc++.h>

using namespace std;

int T[1100000],M,n,ans,m;

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

int maxx(int s,int t)
{
	int Lans=0,Rans=0;
	for (s=s+M,t=t+M;s^t^1 && s<t;s>>=1,t>>=1)
	{
		Lans+=T[s],Rans+=T[t];
		if (!(s&1)) 
			Lans=max(Lans,T[s^1]);
		if (   t&1) 
			Rans=max(Rans,T[t^1]);
	}
	int anss=max(Lans+T[s],Rans+T[t]);
	for (s>>=1;s;s>>=1) anss+=T[s];
	return anss;
}

void build()
{
	for (int i=M-1;i>0;i--) T[i]=max(T[2*i],T[2*i+1]);
	for (int i=M*2-1;i>1;i--) T[i]-=T[i>>1];
}

int main()
{
	scanf("%d",&n);
	for (M=1;M<=n;M<<=1);
	for (int i=1;i<=n;i++) scanf("%d",&T[M+i]);
	build();
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int op,x,y,tmp;
		scanf("%d%d%d",&op,&x,&y);
		if (op==1) scanf("%d",&tmp),add(x,y,tmp);
		else 
		{
			printf("%d\n",maxx(x,y));
		}
	}
}
