#pragma G++ optimize(3)
#pragma GCC optimize(3)
#include <cstdio>
#include <cstring>

using namespace std;

int fx[5]={0,1,0,-1,0},fy[5]={0,0,1,0,-1},F[5]={0,2,3,4,1},K[5]={0,4,1,2,3};
int FX[5]={0,1,1,-1,-1},FY[5]={0,-1,1,1,-1};
int mp[2010][2010],r,c,ans,mx,D,MP[2010][2010];
char s[2010];

int max(int x,int y){return x>y?x:y;}

void clear(int x,int y)
{
	MP[x][y]=0;
	mp[x][y]=1;
	for (int i=1;i<=4;i++)
		if (MP[x+fx[i]][y+fy[i]]==1)
		{
			clear(x+fx[i],y+fy[i]);
		}
}

void doit(int x,int y)
{
	memset(mp,0,sizeof mp);
	clear(x,y);
	int xx=x,yy=y,D,sD;
	for (int i=1;i<=4;i++) 
		if (!mp[x+fx[i]][y+fy[i]]) 
		{
			sD=F[i];
			break;
		}
	D=sD;
	ans=0;
	int flag=0;
	do
	{
		while (mp[xx+fx[D]][yy+fy[D]]) 
		{
			xx+=fx[D],yy+=fy[D];
			ans++;
			if (xx==x && yy==y && D==sD && ans!=0) 
			{
				flag=1;
				break;
			}
		}
		int cnt=0;
		if (flag) break;
		while (D==-1 || mp[xx+fx[D]][yy+fy[D]]==0 && cnt<2)
		{
			if (xx==x && yy==y && D==sD && ans!=0) 
			{
				flag=1;
				break;
			}
			D++;
			if (D==5) D=1;
			ans++;
			cnt++;
		}
		if (flag) break;
		while (mp[xx+FX[D]][yy+FY[D]])
		{
			xx+=FX[D];
			yy+=FY[D];
			D=K[D];
		} 
	}while (xx!=x || yy!=y || D!=sD);
	mx=max(mx,ans);
}

int main()
{
	//freopen("test2.in","r",stdin);
	memset(mp,0,sizeof mp);
	scanf("%d%d",&r,&c);
	for (int i=1;i<=r;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=c;j++)
			if (s[j]=='.') MP[i][j]=1;
	}
	
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++)
			if (MP[i][j]) doit(i,j);
				//sol(i,j);
	printf("%d\n",mx-1);
}
