#pragma G++ optimize(3)
#pragma GCC optimize(3)
#include <cstdio>

using namespace std;

int A,B,ans;

inline int abss(int x){return x>0?x:-x;}

inline int pd(int x)
{
	int now,last=-100;
	while (x)
	{
		now=x%10;
		x/=10;
		if (abss(last-now)<2) return 0;
		last=now;
	}
	return 1;
}

int main()
{
	//freopen("number.in","r",stdin);
	scanf("%d%d",&A,&B);
	for (register int i=A;i<=B;i++)
		if (pd(i)) ans++;
	printf("%d\n",ans);
}