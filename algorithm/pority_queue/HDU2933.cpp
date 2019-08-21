#include<cstdio>

using namespace std;

int n,len,a[110000],sum[110000],q[110000],now;

int ans;

int compare(int i,int j,int k)
{
	return ( (sum[k]-sum[j])*(j-i) <= (sum[j]-sum[i])*(k-j) );
}

int max(int x,int y){return x>y?x:y;}

int main()
{
	scanf("%d%d",&n,&len);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	
	int head=1,tail=0;
	for (int i=len;i<=n;i++)
	{
		now=i-len;

		while ( head<tail && compare( q[tail-1],q[tail],now ) ) tail--;

		q[++tail]=now;

		while ( head<tail && compare( q[head+1],q[head],i ) ) head++;

		ans=max(ans, (sum[i]-sum[q[head]])*1000/(i-q[head]) );
	}

	printf("%d\n",ans);
}