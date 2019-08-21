#include <cstdio>

using namespace std;

int n,k;

int dg(int a,int b)
{
	if (b==0 && a!=1) printf("!%d\n",a);
	if (b==0) return a;
	if (a==0) return 1;
	dg(a-1,b),dg(a,b-1);
	return 0;
	//return dg(a-1,b)*dg(a,b-1);
}

int main()
{
	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&k);
	printf("%d",dg(n,k));
}