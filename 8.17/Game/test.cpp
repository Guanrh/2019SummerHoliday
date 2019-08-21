#include <cstdio>

using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	int k=1;
	for (int i=1;i<n;i++) k*=3;
	int ans=k+(1<<n);
	printf("%d\n",ans);
}