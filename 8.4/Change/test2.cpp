#pragma GCC optimize(3)
#pragma G++ optimize(3)
#include<cstdio>
long long a,b;
int main()
{
	for (register int i=1;i<=1000000;++i) 
		for (register int j=1;j<=1000000;++j)
			++a;
    printf("%lld\n",a);
}