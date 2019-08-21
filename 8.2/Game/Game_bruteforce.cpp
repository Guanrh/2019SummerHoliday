#include<bits/stdc++.h>

using namespace std;

int total,n,a[110],x,flag,ans,win;

void dg(int now,int left,int right,int alice,int bob)
{
	if (bob>=win) flag=0;
	if (!flag) return;
	//if (left==0) left=n;
	//if (right==n+1) right=1;

}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&x);
		if (x%2==1) a[i]=1,total++;
	}
	win=total/2+total%2;
	for (int i=1;i<=n;i++)
	{
		flag=1;
		dg(i,i-1,i+1,a[i],0);
		if (!flag) ans++;
	}

	printf("%d\n",ans);
}