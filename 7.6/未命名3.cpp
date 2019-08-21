#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define mcy(a,b) memcpy(a,b,sizeof(a))
#define ll long long
#define inf 2147483647
#define N 20
#define open(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define INF 2147483647
using namespace std;

int n,i,j,k,t,ans,maxx,p,cnt,sum;
int a[N],bz[N],findtag,suf[N],bz1,bz2,bztmp[N],st[N];

void dfs(int t,int x,int length)
{
	if(findtag) return ;
	if(x > p)
	{
		if(length == t )
			findtag = 1,++cnt;
		return ;
	}
	if(length > t || length + suf[x] < t) return ;
	dfs(t,x+1,length);
	if(findtag) return ;
	if(!bz[x])  
	{
		bz[x]=1;
		st[++st[0]]=x;
		dfs(t,x+1,length + a[x]);
		st[st[0]--]=-0;
		if(findtag) return ;
		bz[x]=0;
	}
		
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]),sum +=a[i];
	sort(a+1,a+1+n);
	maxx = sum / 2;
	for(i=1;i<=maxx;i++)
	{
		mem(bz,0);
		cnt = 0,p=n,bz1=0;
		for(k=1;k<=n;k++) if(a[k] == i) ++cnt,p=k,bz[k]=1;
		if(cnt == 2) bz1=1; else
		{
			mem(suf,0);
			findtag=1;
			p = p - cnt;
			for(int l=p;l>0;l--) suf[l] = suf[l+1] + a[l];
			while(cnt < 2 && findtag) findtag=0,dfs(i,1,0);
			if(cnt == 2) bz1=1;
		}
		if(bz1)
		for(j=ans / i;j<=maxx;j++) if(2*j + 2*i > sum) break;else
		{
			mcy(bztmp , bz);
			cnt=0,p=n,bz2=0;
			for(k=1;k<=n;k++) if(a[k] == j && !bz[k]) ++cnt,p=k,bz[k]=1;
			if(cnt==2) bz2=1; else
			{
				mem(suf,0);
				findtag =1;
				p = p -cnt;
				for(int l=p;l>0;l--) if(bz[l]==0) suf[l] = suf[l+1] + a[l] ;else suf[l] = suf[l+1];
				while(cnt < 2 && findtag) 
					findtag=0,dfs(j,1,0);
				if(cnt==2) bz2=1;
			}
			mcy(bz,bztmp);
			if(bz2) //ans = max(ans , i*j);
			{
				if (i*j>ans) printf("%d %d\n",i,j);
				ans = max(ans , i*j);
			}
		}
	}
	if(ans)printf("%d\n",ans); else printf("No Solution");
	return  0;
}
