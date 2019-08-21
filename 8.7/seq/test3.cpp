#include<cstdio>
#include<cstring>
#define mo 100000000

using namespace std;

int mat[3][3],f[3][3],c[3][3];
int ans[3][3],res[3][3];

int T,x,y;

int fab(int x)
{
	f[1][1] = 2;
	f[1][2] = 3;
	mat[1][1] = 0;
	mat[2][1] = mat[1][2] = mat[2][2] =1;
	memset(ans,0,sizeof ans);
	memset(res,0,sizeof res);
	for (int i = 1;i <= 1;i ++)
		for (int j = 1;j <= 2;j ++)
			for (int k = 1;k <= 2;k ++)
					ans[i][j] += f[i][k] * mat[k][j],ans[i][j] %= mo,printf("%d %d + %d %d * %d %d\n",i,j,i,k,k,j);
	printf("%d %d\n",ans[1][1],ans[1][2]);
	return ans[1][2];
}

int main()
{
	//scanf("%d",&T);
	fab(1);
	//while ( T-- )
	//{
		//scanf("%d",&x);
		//int ans = (fab(x-2)) % mo;
		//printf("%d\n",ans);
	//}
}
