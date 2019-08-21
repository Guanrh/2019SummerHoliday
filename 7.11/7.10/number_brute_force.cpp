#include <bits/stdc++.h>

using namespace std;

int n,k,a[20];

int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i ++) scanf("%d",&a[i]);
	int cnt = 0;		
	for (int i = 1;;i ++)
	{
		int tmp = 0;
		for (int j = 1;j <= n;j ++)
			if ( i % a[j] == 0 ) tmp ++;
		if (tmp == 1) cnt ++;
		if (cnt == k) 
		{
			printf("%d\n",i);
			return 0;
		} 
	}
}