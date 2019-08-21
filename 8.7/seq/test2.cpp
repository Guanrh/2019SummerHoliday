#include<cstdio>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	long long k=1;
	for (int i=1;i<=10;i++)
	{
		k*=n;
		printf("%lld ",k);
	}
}