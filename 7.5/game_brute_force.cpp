#include<cstdio>

using namespace std;

int n,m;
int ans;

int min(int x,int y){return x<y?x:y;}

int dfs(int left,int K,int last)
{
	int flag;
	if (last*K>=left && last!=99999999) return 1;
	for (int i=1;i<=last*K && i<=n-1;i++)
	{
		flag=1;
		int rest=left-i;
		if (rest<=i*K) 
		{
			flag=0;
			break;
		}
		for (int j=1;j<=i*K;j++)
		{
			flag&=dfs(rest-j,K,j);
		}
		if (flag && last==99999999) ans=min(ans,i);
		if (flag) return 1;
	}
	return flag;
}

int main()
{
	//scanf("%d%d",&n,&m);
	//////ans=999;
	//if (dfs(n,m,99999999)) printf("YES %d\n",ans);
///	else printf("NO\n");
	freopen("bf.out","w",stdout);
	//freopen("test.in","r",stdin);
	for (n=2;n<=35;n++)
	{
		for (m=1;m<=7;m++)
		{
			ans=99999999;
			if (dfs(n,m,99999999)) printf("%d ",ans);
				else printf("X ");
		}
		printf("\n");
	}
}
