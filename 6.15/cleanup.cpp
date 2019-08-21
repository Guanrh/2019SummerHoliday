#include<bits/stdc++.h>

using namespace std;

int n,m,p[41000],vis[41000],ans,que[41000],tot,cnt;

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) p[i]=read();
	
	for (int now=1;now<=n;)
	{
		int nxt=now+1;
		tot=0;
		que[++tot]=p[now];
		vis[p[now]]=1;
		while (1 && now<=n)
		{
			if (vis[p[nxt]]) nxt++;
			else
			{
				if ((tot+1)*(tot+1)<=nxt-now+1)
				{
					que[++tot]=p[nxt];
					vis[p[nxt]]=1;
					nxt++;
				}
				else
					break;
			}
		}
		now=nxt;
		ans+=tot*tot;
		for (int i=1;i<=tot;i++) vis[que[i]]=0;
	}
	printf("%d\n",ans);
} 
