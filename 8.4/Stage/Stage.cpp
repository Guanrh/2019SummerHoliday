#include<cstdio>
#include<cstring>

using namespace std;

int n,m,x,y,k,mp[210][210],f[210][210][210],S,T,D;
char c,s[210];
int fx[5][3];

int max(int x,int y){return x>y?x:y;}

int main()
{
	//freopen("stage.in","r",stdin);
	fx[1][1]=-1,fx[2][1]=1,fx[3][2]=-1,fx[4][2]=1;
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&k);
	memset(mp,0,sizeof mp);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)	
				mp[i][j]=(s[j]=='.');
	}

	memset(f,255,sizeof f);
	f[0][x][y]=0;
	for (int p=1;p<=k;p++)
	{
		scanf("%d%d%d",&S,&T,&D);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (f[p-1][i][j]!=-1)
				{
					f[p][i][j]=max(f[p][i][j],f[p-1][i][j]);
					int xx=i,yy=j;
					for (int t=1;t<=T-S+1;t++)
					{
						xx+=fx[D][1],yy+=fx[D][2];
						if (xx<1 || yy<1 || xx>n || yy>m || !mp[xx][yy]) break;
						f[p][xx][yy]=max(f[p][xx][yy],f[p-1][i][j]+t);
					}
				}
	}

	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ans=max(ans,f[k][i][j]);
	printf("%d\n",ans);
}
