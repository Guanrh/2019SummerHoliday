//#pragma G++ optimize(3)
//#pragma GCC optimize(3)
#include <cstdio>
#include <cstring>
#define water 2
#define rock 3
#define home 4

using namespace std;

struct node 
{
	int x,y,tim;
}q[3100000];

int mp[2510][52][52],sx,sy,tx,ty,r,c,head,tail,bz[55][55],flag;
char s[60];	
int fx[5]={0,1,0,-1,0},fy[5]={0,0,1,0,-1};

void predo()
{
	for (register int time=2;time<=r*c;time++)
	{
		memcpy(mp[time],mp[time-1],sizeof mp[1]);
		for (register int i=1;i<=r;i++)
			for (register int j=1;j<=c;j++)
				if (mp[time-1][i][j]==water)
					for (register int ff=1;ff<=4;ff++)
						if (mp[time-1][i+fx[ff]][j+fy[ff]]!=rock && mp[time-1][i+fx[ff]][j+fy[ff]]!=home)
							mp[time][i+fx[ff]][j+fy[ff]]=water;
	}

}

void bfs()
{
	head=0;tail=1;
	q[1].x=sx;
	q[1].y=sy;
	q[1].tim=1;
	memset(bz,0,sizeof bz);
	bz[sx][sy]=1;
	while (head<tail)
	{
		head++;
		for (int ff=1;ff<=4;ff++)
		{
			int xx=q[head].x+fx[ff],yy=q[head].y+fy[ff],now=q[head].tim+1;
			//if (mp[q[head].tim][q[head].x][q[head].y]==water) return;
			if (!bz[xx][yy] && xx>0 && yy>0 && xx<=r && yy<=c && mp[now][xx][yy]!=rock && mp[now][xx][yy]!=water)
			{
				tail++;
				bz[xx][yy]=1;
				q[tail].x=xx;
				q[tail].y=yy;
				q[tail].tim=now;
				if (xx==tx && yy==ty)
				{
					printf("%d\n",now-1);
					flag=1;
					return;
				}
			}
		}
	}
}

int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	memset(mp,0,sizeof mp);
	scanf("%d%d",&r,&c);
	for (register int i=1;i<=r;i++)
	{
		scanf("%s",s+1);
		for (register int j=1;j<=c;j++)
			if (s[j]=='*') mp[1][i][j]=water;
			else if (s[j]=='X') mp[1][i][j]=rock;
			else if (s[j]=='S') sx=i,sy=j;
			else if (s[j]=='D') tx=i,ty=j,mp[1][i][j]=home;
	}
	predo();
	flag=0;
	bfs();
	if (!flag) printf("KAKTUS\n");
}
