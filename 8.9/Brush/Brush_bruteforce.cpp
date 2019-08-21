#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,t,ans,wz[30][30],b[30][30],r[30][30],q[900],tot;
char s[30][30];

int max(int x,int y){return x>y?x:y;}

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for (int i=1;i<=n;i++) 
	{
		scanf("%s",s[i]+1);
		for (int j=1;j<=m;j++)
		{
			b[i][j]=b[i][j-1],r[i][j]=r[i][j-1];
			if (s[i][j]=='0') r[i][j]++;
			else b[i][j]++;
		}
		q[++tot]=max(r[i][m],b[i][m]);
	}
	sort(q+1,q+1+tot);
	int ans=0;
	for (int i=tot;i>=1 && t;i--)
	{
		ans+=q[i];
		t--;
	}
	printf("%d\n",ans);
}
