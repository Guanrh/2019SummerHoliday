#pragma G++ optimize(3)
#pragma GCC optimize(3)
#include <cstdio>

using namespace std;

char s[2010];
int a[2002][2002],r[2002][2002],l[2002][2002],h[2002][2002],R,C,x,y,ll,rr,ans;

int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}

int main()
{
	scanf("%d%d",&R,&C);
	for (int i=1;i<=R;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=C;j++)
			if (s[j]=='.') a[i][j]=5;
	}
	for (int i=1;i<=R;i++)
		for (int j=1;j<=C;j++)
			if (a[i][j])
			{
				x=i,y=j;
				while (a[x-1][y]==5) x--;
				h[i][j]=x;
				x=i,y=j;
				while (a[x][y+1]==5) y++;
				r[i][j]=y;
				x=i,y=j;
				while (a[x][y-1]==5) y--;
				l[i][j]=y;
			}

	for (int i=1;i<=R;i++)
		for (int j=1;j<=C;j++)
			if (a[i][j])
			{
				ll=-999999999;
				rr=999999999;
				for (int k=i;k>=h[i][j];k--)
				{
					ll=max(ll,l[k][j]);
					rr=min(rr,r[k][j]);
					ans=max(ans,(i-k+1+rr-ll+1)*2);
				}
			}
	printf("%d\n",ans-1);
}
