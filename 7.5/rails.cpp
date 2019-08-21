#include<bits/stdc++.h>

using namespace std;

int n,a[1100],b[1100],top,cur;

int main()
{
	while (1)
	{
		scanf("%d",&n);
		if (n==0) return 0;
		while (1)	
		{
			scanf("%d",&b[1]);if (b[1]==0) break;
			for (int i=2;i<=n;i++) scanf("%d",&b[i]);
			top=0;
			cur=1;
			int flag=1;
			for (int i=1;i<=n;i++)
			{
				while (cur<=b[i]) a[++top]=cur,cur++;
				if (a[top]!=b[i])
				{
					flag=0;
					break;
				}
				else
				{
					top--;
				}
			}
			if (flag) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
}
