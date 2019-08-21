#include <cstdio>

using namespace std;

int T;
long long b,a,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int sum=0;
		scanf("%lld%lld%lld",&a,&b,&n);
		for (int i=1;i<=n;i++)
		{
			b+=a;
			long long x=b;
			while (x)
			{
				sum+=x&1;
				x>>=1;
			}
		}
		printf("%d\n",sum);
	}
}