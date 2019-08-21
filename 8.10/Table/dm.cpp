#include <cstdio>

using namespace std;

int n;

int main()
{
	freopen("test2.in","w",stdout);
	scanf("%d",&n);
	printf("%d %d\n",n,n);
	for (int i=1;i<=n/4;i++)
	{
		for (int j=1;j<=n;j++) printf(".");
		printf("\n");
		for (int j=1;j<=n-1;j++) printf("X");
		printf(".\n");
		for (int j=1;j<=n;j++) printf(".");
		printf("\n");
		printf(".");
		for (int j=1;j<=n-1;j++) printf("X");
		printf("\n");
	}
}