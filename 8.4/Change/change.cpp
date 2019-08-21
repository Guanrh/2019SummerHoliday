#include <cstdio>

using namespace std;

int n,a[2100000],l;

int max(int x,int y){return x<y?x:y;}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) a[i]=i;
	l=0;
	for (int i=2;i<=n;i++)
	{
		a[n+i-1]=a[(n/i)*i+i-1];
		for (int j=(n/i);j>=1;j--) a[i*j+i-1]=a[i*j-1];
	}
	for (int i=n;i<=n*2-1;i++) printf("%d ",a[i]);
}