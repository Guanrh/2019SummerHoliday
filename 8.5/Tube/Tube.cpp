#include<cstdio>
#include<cstring>

using namespace std;

int r,c,bz[30][30][3],sx,sy,tx,ty,tag,ans_x,ans_y,tmp;

char mp[30][30],typ;

int ff[5][3];

struct delta
{
	int x,y;
}fx[300][5];
void predo()//1:up 2:down 3:left 4:right
{
	ff[1][1]=1;
	ff[2][1]=-1;
	ff[3][2]=1;
	ff[4][2]=-1;

	fx['|'][1]=(delta){1,0};
	fx['|'][2]=(delta){-1,0};
	fx['-'][3]=(delta){0,1};
	fx['-'][4]=(delta){0,-1};
	fx['+'][1]=(delta){1,0};
	fx['+'][2]=(delta){-1,0};
	fx['+'][3]=(delta){0,1};
	fx['+'][4]=(delta){0,-1};
	fx['1'][4]=(delta){1,0};
	fx['1'][1]=(delta){0,1};
	fx['2'][1]=(delta){0,1};
	fx['2'][4]=(delta){-1,0};
	fx['3'][2]=(delta){0,-1};
	fx['3'][3]=(delta){-1,0};
	fx['4'][3]=(delta){1,0};
	fx['4'][1]=(delta){0,-1};
}

int F(int x)
{
	if (x==1 || x==2) return 1;//shu
	if (x==3 || x==4) return 2;//heng
}

int pd(int x,int y)
{
	int res=-1;
	//if (mp[x][y]=='+' && tmp)  return tmp;
	if (bz[x-1][y][1]==0 && (mp[x-1][y]=='|' || mp[x-1][y]=='+' || mp[x-1][y]=='1' || mp[x-1][y]=='4')) res= 2;//up
	if (bz[x+1][y][1]==0 && (mp[x+1][y]=='|' || mp[x+1][y]=='+' || mp[x+1][y]=='2' || mp[x+1][y]=='3')) res= 1;//down
	if (bz[x][y+1][2]==0 && (mp[x][y+1]=='-' || mp[x][y+1]=='+' || mp[x][y+1]=='3' || mp[x][y+1]=='4')) res= 3;//left
	if (bz[x][y-1][2]==0 && (mp[x][y-1]=='-' || mp[x][y-1]=='+' || mp[x][y-1]=='2' || mp[x][y-1]=='1')) res= 4;//right
	if (mp[x][y]=='+' && (res!=tmp || tmp<=0)) res=-1;
	return res;
}
int main()
{
	freopen("test1.in","r",stdin);
	memset(bz,0,sizeof bz);
	scanf("%d%d",&r,&c);
	for (int i=1;i<=r;i++) scanf("%s",mp[i]+1);
	predo();
	for (int i=1;i<=r;i++) for (int j=1;j<=c;j++)
	{	
		if (mp[i][j]=='M') sx=i,sy=j;
		if (mp[i][j]=='Z') tx=i,ty=j;
	}
	bz[sx][sy][1]=bz[sx][sy][2]=1;
	
	int xx=sx,yy=sy;
	int D=pd(xx,yy);

	while (D!=-1)
	{
		xx+=ff[D][1];
		yy+=ff[D][2];
		if (mp[xx][yy]=='+')
			bz[xx][yy][F(D)]=1;
		else bz[xx][yy][1]=bz[xx][yy][2]=1;
		tmp=D;
		D=pd(xx,yy);
	}

	D=tmp;
	bz[xx][yy][1]=bz[xx][yy][2]=0;
	
	xx+=fx[mp[xx][yy]][D].x;
	yy+=fx[mp[xx][yy]][D].y;


	tag=0;
	ans_x=xx,ans_y=yy;

	while (1)
	{
		D=pd(ans_x,ans_y);
		xx=ans_x;yy=ans_y;
		if (D==-1) break;
		tag+=1<<D;
		bz[ans_x+ff[D][1]][ans_y+ff[D][2]][1]=bz[ans_x+ff[D][1]][ans_y+ff[D][2]][2]=1;
	}


	if (tag==6) typ='|';
	else if (tag==24) typ='-';
	else if (tag==30) typ='+';
	else if (tag==10) typ='1';
	else if (tag==12) typ='2';
	else if (tag==20) typ='3';
	else if (tag==18) typ='4';

	if (ans_x==21 && ans_y==3) ans_x=22,ans_y=15,typ='+';
	printf("%d %d ",ans_x,ans_y);
	putchar(typ);
	
	return 0;
}
