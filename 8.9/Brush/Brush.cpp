#include <cstdio>

using namespace std;

int n,m,t,f[60][2510][3];

char s[60];

int max(int x,int y){return x>y?x:y;}

int main()
{
	scanf("%d%d%d\n`",&n,&m,&t);
	for (int i=1;i<=n;i++) 
	{
		scanf("%s",&s);
		for (int j=1;j<=t;j++) 
			f[0][j][0]=max(f[m][j][0],max(f[m][j][1],f[m][j][2]));
		for (int j=1;j<=m;j++)
			for (int k=1;k<=t;k++)
			{
				f[j][k][0]=max(f[j-1][k][0],max(f[j-1][k][1],f[j-1][k][2]));
				f[j][k][1]=max(f[j-1][k-1][0],max(f[j-1][k][1],f[j-1][k-1][2]))+(s[j-1]=='0');
				f[j][k][2]=max(f[j-1][k-1][0],max(f[j-1][k-1][1],f[j-1][k][2]))+(s[j-1]=='1');
			}
	}
	int ans=max(f[m][t][0],max(f[m][t][1],f[m][t][2]));
	printf("%d\n",ans);
}
