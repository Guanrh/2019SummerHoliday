#include <cstdio>

using namespace std;

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); }

int a,b,tmp;

int main()
{
	scanf("%d%d",&a,&b);
	tmp=gcd(a,b);
	printf("%d %d\n",a/tmp,b/tmp);
}