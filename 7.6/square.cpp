#include<bits/stdc++.h>

using namespace std;

int sum,n,a[20],ans,flag,cnt,vis[20],stk[20],top,vis2[20];

int max(int x,int y){return x>y?x:y;}

void dfs(int x,int len,int target)
{
	if (flag) return;
	if (x>n)
	{
		if (len==target) 
		{
			flag=1,cnt++;
			for (int i=1;i<=top;i++) vis[stk[i]]=2;
		}
		return;
	}
	dfs(x+1,len,target);
	if (vis[x]) return;
	if (len+a[x]<=target) 
	{
		vis[x]=1;
		stk[++top]=x;
		dfs(x+1,len+a[x],target);
		--top;
		if (vis[x]!=2) vis[x]=0;
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=sum/2;i++)
	{
		memset(vis,0,sizeof vis);
		cnt=0;
		for (int p=1;p<=n;p++) 
		 	if(a[p]==i) ++cnt,vis[p]=1;
		flag=1;
		while (cnt<2 && flag) flag=0,dfs(1,0,i);
		if (cnt<2) continue;
		memcpy(vis2,vis,sizeof vis);
		for (int j=1;j<=sum/2;j++)
		{
			cnt=0;
			for (int p=1;p<=n;p++) 
				if (a[p]==j && !vis[p]) ++cnt,vis[p]=1;
			flag=1;
			while (cnt<2 && flag) flag=0,dfs(1,0,j);
			memcpy(vis,vis2,sizeof vis);
			if (cnt<2) continue;
			ans=max(ans,i*j);
		}
	}
	if (ans==0) printf("No Solution\n");
	else
	printf("%d\n",ans);
}
