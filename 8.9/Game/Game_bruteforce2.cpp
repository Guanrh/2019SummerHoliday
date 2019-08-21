#include <cstdio>
#include <cstring>

using namespace std;

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); }
int lcm(int a,int b){return (a*b/gcd(a,b));}

int n,f[11000000],ans,bz[1100];

void dg(int rest,int k)
{
	f[k]=1;
	for (int i=2;i<=rest;i++)
	if (!bz[i])
	{
		bz[i]=1;
		dg(rest-i,lcm(k,i));
		bz[i]=0;
	}
}

int main()
{
	scanf("%d",&n);
	dg(n,1);
	for (int i=1;i<=1100000;i++) if (f[i]==1) ans++;
	printf("%d\n",ans);
}
