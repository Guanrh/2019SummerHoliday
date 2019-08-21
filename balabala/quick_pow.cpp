#include <bits/stdc++.h>

using namespace std;

int base,p,mo;

int qpow(int a,int b)
{
	if (b == 0) return 1;
	int res = qpow(a,b>>1);
	res = (res*res) % mo;
	if ( b % 2 ) res*=a;
	return res % mo;
}

int main()
{
	scanf("%d%d%d",&base,&p,&mo);
	//printf("%d\n",qpow(base,p));
	printf("%d^%d mod %d=%d\n",base,p,mo,qpow(base,p));
}