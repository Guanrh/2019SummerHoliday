
#include <cstdio>

using namespace std;

int a[1100],b[1100],ans,sum,n,mn,mx,wz;

int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}

int main()
{
	scanf("%d",&n);
	mn=999999999;
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),mn=min(mn,a[i]),mx=max(mx,b[i]);
	for (int i=mn;i<=mx;i++)
	{
		sum=0;
		for (int j=1;j<=n;j++)
			if (i<a[j]) sum+=a[j];
			else if (i>=a[j] && i<=b[j]) sum+=i;
		if (sum>ans)
		{
			ans=sum;
			wz=i;
		}
	}
	printf("%d %d\n",wz,ans);
}
