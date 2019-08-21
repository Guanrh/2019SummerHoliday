#include<bits/stdc++.h>

using namespace std;

int total,n,a[110],x,flag,ans,win;



int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&x);
		if (x%2==1) a[i]=1,total++;
	}

	printf("%d\n",total);
}