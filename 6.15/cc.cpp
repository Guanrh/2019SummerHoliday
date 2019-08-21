#include<bits/stdc++.h>

using namespace std;

int n,m,p[41000],vis[41000],ans,tot,cnt,f[41000],kind,que[41000];

int min(int x,int y){return x<y?x:y;}

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
	freopen("cleanup.in","r",stdin);
	freopen("cleanup.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) p[i]=read();
	
	f[1]=1;
	for (int i=2;i<=n;i++)
	{
		f[i]=f[i-1]+1;
		kind=1;
		que[1]=p[i];
		vis[p[i]]=1;
		for (int j=i-1;j>=1;j--)
		{
			if (!vis[p[j]]) que[++kind]=p[j],vis[p[j]]=1;
			if (kind*kind>i) break;
			f[i]=min(f[i],f[j-1]+kind*kind);
		}
		for (int i=1;i<=kind;i++) vis[que[i]]=0;
	}
	printf("%d\n",f[n]);
	//printf("!!!");
	//for (int i=1;i<=n;i++) printf("%d\n",f[i]);
} 
