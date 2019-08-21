#include<cstdio>

using namespace std;

int n,k,num,sx,sy,tx,ty,a[2100][2100];

void find(int NUMBER)
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (a[i][j]==NUMBER)
			{
				sx=i,sy=j;
				return;
			}
}

int main()
{
	scanf("%d%d",&n,&k);
	int cnt=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=++cnt;
	for (int T=1;T<=k;T++)
	{
		scanf("%d%d%d",&num,&tx,&ty);
		find(num);
	}
}