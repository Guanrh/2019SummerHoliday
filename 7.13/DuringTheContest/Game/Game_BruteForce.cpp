#include<bits/stdc++.h>

using namespace std;

int T,k,n,flag;

int dg(int left)
{
	if (left<=k) 
	{
		return 1;
	}
	for (int i=1;i<=k;i++)
	{
		int now=left-i;
		int flag=1;
		if (now<=k) return 0;
		for (int j=1;j<=k;j++)
			flag&=dg(now-j);
		if (flag) return 1;
	}
	return 0;
}

int main()
{
	/*scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&k,&n);
		int ff=dg(n);
		if (ff) printf("YES\n");
		else printf("NO\n");
	}*/

	for (k=1;k<=10;k++)
	{
		for (n=1;n<=10;n++)
			{
				//scanf("%d%d",&k,&n);
				int ff=dg(n);
				if (ff) printf("Y ");
				else printf("N ");
			}
		printf("\n");
	}
}