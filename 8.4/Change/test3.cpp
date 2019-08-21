#pragma GCC optimize(3)
#pragma G++ optimize(3)
#include<cstdio>
int k,cnt;
long long a;
int main()
{
	freopen("test3.out","w",stdout);
	k=1;
	cnt=0;
	for (register int i=1000000;i>=1;--i)
	{
		int len=1000000/i;
		while (k<len) k*=2,cnt++;
		a+=i*cnt;
		printf("%d\n",cnt);
	} 
    printf("%lld\n",a);
}