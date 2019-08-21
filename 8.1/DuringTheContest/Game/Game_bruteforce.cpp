#include<bits/stdc++.h>

using namespace std;

int T,k,n,flag;
int a[110][110];

int pdr(int r,int c)
{
	int res=0;
	for (int i=1;i<=c;i++) res+=a[r][i];
	if (res%2==0) return 1;
	else return 0;
}

int pdc(int r,int c)
{
	int res=0;
	for (int i=1;i<=r;i++) res+=a[i][c];
	if (res%2==0) return 1;
	else return 0;
}

int dg(int r,int c)
{
	if (r<=0 || c<=0) return 0;
	int fr=pdr(r,c),fc=pdc(r,c);
	if (!(fr || fc)) 
	{
		return 0;
	}
	
	int flag1=1,flag2=1;

	r--;
	if (pdr(r,c)) flag1&=dg(r-1,c);
	if (pdc(r,c)) flag1&=dg(r,c-1);
	r++;

	c--;
	if (pdr(r,c)) flag2&=dg(r-1,c);
	if (pdc(r,c)) flag2&=dg(r,c-1);
	c++;

	int flag=(flag1 || flag2);

	return flag;
}

int main()
{
	//freopen("test.in","r",stdin);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		int ff=dg(n,n);
		if (ff) printf("W\n");
		else printf("L\n");
	}
}
