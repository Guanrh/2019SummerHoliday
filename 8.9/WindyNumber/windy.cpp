#include <cstdio>
#include <cstring>
#define inf 2147483600

using namespace std;

int A,B,f[25][10],len,num[25];

int abss(int x){return x>0?x:-x;}


int dfs(int pos,int limit,int lead,int last)
{
	if (pos==0) return 1;
	if (!limit  && !lead && f[pos][last]) return f[pos][last];
	int up=limit?num[pos]:9,total=0;
	for (int i=0;i<=up;i++)
		if (abss(last-i)>1 || lead)
			total+=dfs(pos-1,limit && (i==up),lead && (i==0),i);
	if (!lead && !limit) f[pos][last]=total;
	return total;
}

void split(int x)
{
	memset(num,0,sizeof num);
	len=0;
	while (x)
	{
		num[++len]=x%10;
		x/=10;
	}
}

int sol(int x)
{
	split(x);
	return dfs(len,1,1,inf);
}

int main()
{
	scanf("%d%d",&A,&B);
	printf("%d\n",sol(B)-sol(A-1));
}