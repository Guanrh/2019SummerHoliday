#include<bits/stdc++.h>
#define mo 10000

using namespace std;

int mat[3][3],f[3][3],c[3][3];
int ans[3][3],res[3][3];

int T,x,y;

void qpow(int x)
{
	if (x==0) 
	{
		res[2][2]=res[1][1]=1;
		return;
	}
	qpow(x>>1);
	//mul(res,res);
	memset(c,0,sizeof c);
	for (int i=1;i<=2;i++)
		for (int j=1;j<=2;j++)
			for (int k=1;k<=2;k++)
				c[i][j]=(c[i][j]+res[i][k]*res[j][k])%mo;
	memcpy(res,c,sizeof c);
	if (x%2)
	{
		memset(c,0,sizeof c);
		for (int i=1;i<=2;i++)
			for (int j=1;j<=2;j++)
				for (int k=1;k<=2;k++)
					c[i][j]=(c[i][j]+res[i][k]*mat[j][k])%mo;
		memcpy(res,c,sizeof c);
	}
	
}

int fab(int x)
{
	if ( x == 0 ) return 0;
	if ( x == 1 ) return 1;
	f[1][1] = f[1][2] = 1;
	mat[1][1] = 0;
	mat[2][1] = mat[1][2] = mat[2][2] =1;
	memset(ans,0,sizeof ans);
	memset(res,0,sizeof res);
	qpow(x);
	for (int i = 1;i <= 1;i ++)
		for (int j = 1;j <= 2;j ++)
			for (int k = 1;k <= 2;k ++)
					ans[i][j] += f[i][k] * res[k][j],ans[i][j] %= mo;
	return ans[1][2]-1;
}

int main()
{
	scanf("%d",&T);
	while ( T-- )
	{
		scanf("%d%d",&x,&y);
		int ans = ( fab(y) - fab(x-1) + mo ) % mo;
		printf("%d\n",ans);
	}
}
